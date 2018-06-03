/***************************************************************************//**
* \file sbp_device.c
*
* \brief Standalone C Driver for the Swift-Nav SBP Devices
* \author Josh Kretzmer
* \date June 23, 2017
*
* Adapted from original Swift-Nav Piksi driver authored by:
* Scott K Logan
* Caleb Jamison
* 
*
* This is a standalone C driver for the Swift Navigation SBP Devices.
*
* \section license License (BSD-3)
* Copyright (c) 2013, Scott K Logan\n
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
* - Redistributions of source code must retain the above copyright notice,
* this list of conditions and the following disclaimer.
* - Redistributions in binary form must reproduce the above copyright notice,
* this list of conditions and the following disclaimer in the documentation
* and/or other materials provided with the distribution.
* - Neither the name of Willow Garage, Inc. nor the names of its contributors
* may be used to endorse or promote products derived from this software
* without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
* AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
* IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
* ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
* LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
* CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
* SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
* INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
* CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
* ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
******************************************************************************/

#include "swiftnav_ros/sbp_device.h"

#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <fcntl.h>
#include <stdio.h>

/*!
 * \brief Maximum number of simultaneously open device handles.
 */
#define MAX_HANDLES 256

#define NO_FLUSH_BUFFER 1

struct piksi_priv
{
	int fd;
	int baud;
	char *port;
};

/*!
 * \brief List of communication handles.
 */
static struct piksi_priv * piksi_list[MAX_HANDLES] = { NULL };


/*!
 * \brief Grabs the next available device handle slot.
 *
 * Iterates through the ::MAX_HANDLES slots for the lowest available index.
 *
 * \returns Open slot index between 0 and ::MAX_HANDLES
 * \retval -1 No available slots
 */
static int next_available_handle( )
{
	unsigned short int i;
	for( i = 0; i < MAX_HANDLES; i++ )
	{
		if( !piksi_list[i] )
			return i;
	}
	return -1;
}

static int baud2term( int baud )
{
	switch( baud )
	{
	case 1200:
		return B1200;
		break;
	case 2400:
		return B2400;
		break;
	case 4800:
		return B4800;
		break;
	case 9600:
		return B9600;
		break;
	case 19200:
		return B19200;
		break;
	case 38400:
		return B38400;
		break;
	case 57600:
		return B57600;
		break;
	case 115200:
		return B115200;
		break;
	case 230400:
		return B230400;
		break;
	case 460800:
		return B460800;
		break;
	case 921600:
		return B921600;
		break;
	case 1000000:
		return B1000000;
		break;
	default:
		return B0;
		break;
	}
}

u32 send_cmd( u8 *data, u32 num_bytes, void* context )
{
	int8_t piksid = *( int8_t* ) context;
	return write( piksi_list[piksid]->fd, data, num_bytes );
}

u32 read_data( u8 *data, u32 num_bytes, void* context )
{
	int8_t piksid = *( int8_t* ) context;
	u32 bytes_recv = 0;
	u32 bytes_recvd = 0;
	while( num_bytes )
	{
		bytes_recv = read( piksi_list[piksid]->fd, data, num_bytes );
		if( bytes_recv <= 0 )
			return 0;
		num_bytes -= bytes_recv;
		bytes_recvd += bytes_recv;
	}
	return bytes_recvd;
}


int piksi_open( const char *port, int baud )
{
	/* Step 1: Make sure the device opens OK */
	int fd = open( port, O_RDWR | O_NOCTTY | O_NDELAY );
	if( fd < 0 )
		return PIKSI_ERROR_NO_DEVICE;

	fcntl( fd, F_SETFL, 0 );

	struct termios options;
	cfmakeraw( &options );
	if( cfsetispeed( &options, baud2term(baud) ) < 0 )
	{
		close( fd );
		return PIKSI_ERROR_IO;
	}
	options.c_cflag &= ~HUPCL;
	options.c_lflag &= ~ICANON;
	options.c_cc[VTIME] = 2;
	options.c_cc[VMIN] = 0;
	if( tcsetattr( fd, TCSANOW, &options ) < 0 )
	{
		close( fd );
		return PIKSI_ERROR_IO;
	}

	/* Step 2: Allocate a private struct */
	int mydev = next_available_handle( );
	if( mydev < 0 )
		goto close_mem_error;

	piksi_list[mydev] = malloc( sizeof( struct piksi_priv ) );
	if( !piksi_list[mydev] )
		goto null_struct;

	memset( piksi_list[mydev], 0, sizeof( struct piksi_priv ) );

	piksi_list[mydev]->port = malloc( strlen( port ) + 1 );
	if( !piksi_list[mydev]->port )
		goto free_struct;

	memcpy( piksi_list[mydev]->port, port, strlen( port ) + 1 );
	piksi_list[mydev]->fd = fd;
	piksi_list[mydev]->baud = baud2term(baud);

	return mydev;

	/* Free gotos */

	free_struct:
		free( piksi_list[mydev] );
	null_struct:	
		piksi_list[mydev] = NULL;
	close_mem_error:
		close( fd );
		return PIKSI_ERROR_NO_MEM;
}

void piksi_close( const int8_t piksid )
{
	if( piksid < 0 || piksid > MAX_HANDLES || !piksi_list[piksid] )
		return;

	close( piksi_list[piksid]->fd );

	free( piksi_list[piksid]->port );
	free( piksi_list[piksid] );
	piksi_list[piksid] = NULL;

	return;
}

int main()
{
	return 0;
}

