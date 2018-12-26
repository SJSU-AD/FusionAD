#include <stdio.h>
#include <gsl/gsl_statistics_double.h>
#include <gsl/gsl_matrix_double.h>
#include "covar.h"

void print_mat(gsl_matrix* C)
{
    int i, j;
    for (i = 0; i < C->size1; i++)
    {
        printf("\n");
        for (j = 0; j < C->size2; j++)
        {
            printf("%f", C->data[C->size2*i+j]);
            if(j < C->size2 - 1) printf(", ");
        }
    }
    printf("\n");
}


int main()
{
    int i, j;

/* 
    Okay, here's what we want to do
    1)  Collect *all* the data - 10 seconds at standstill should be sufficient, with
            x, y, z, yaw, pitch, roll; for both pose and twist
    2)  twist gives us euler angles (yaw pitch roll), but pose gives us quaternions,
            so we'll need to convert
    2)  This leads to a 6 by N matrix of values
    3)  We propose a cov_gen() function
            input: 6 by N matrix of observation values
            output: 6 by 6 matrix of covariance values
    4) We can put a ROS wrapper around this function as a service routine,
            i.e. the output of cov_gen() will serve as our estimate of
            the covariance matrix for loam_velodyne's odometry topic
 */

    // const int rsize = 5;
    // const int csize = 3;
    #define rsize 8
    #define csize 6

    double dataA[rsize][csize] =  
        {{9, 6, 9, 3, 2, 1},
         {9, 9, 3, 4, 3, 5},
         {6, 6, 6, 6, 7, 3},
         {6, 6, 9, 4, 5, 1},
         {9, 9, 3, 4, 3, 5},
         {6, 6, 6, 6, 7, 3},
         {6, 6, 9, 4, 5, 1},
         {3, 3, 3, 6, 4, 1}};

    // double dataA[rsize][csize] =  
    //     {{90, 60, 90},
    //      {90, 90, 30},
    //      {60, 60, 60},
    //      {60, 60, 90},
    //      {30, 30, 30}};

    // double dataA[5][3] =   {{ 24,   0,  30},
    //                         { 24,  30, -30},
    //                         { -6,   0,   0},
    //                         { -6,   0,  30},
    //                         {-36, -30, -30}};

    // double dataA[6][6] = {{1,1,1,1,1,1},
    //                       {2,2,2,2,2,2},
    //                       {3,3,3,3,3,3},
    //                       {4,4,4,4,4,4},
    //                       {5,5,5,5,5,5},
    //                       {6,6,6,6,6,6}};
    
    covar my_covar;
    for (i = 0; i < rsize; i++)
        my_covar.insert(dataA[i]);
    my_covar.print_dp();
    my_covar.generate_covar();
    my_covar.print_mat();

    // gsl_vector_view a, b;

    // gsl_matrix *A, *C;
    // A = gsl_matrix_alloc(rsize, csize);
    // C = gsl_matrix_alloc(csize, csize);

    // for ( i = 0; i < rsize; i++)
    //     for ( j = 0; j < csize; j++) 
    //         gsl_matrix_set (A, i, j, dataA[i][j]);

    // print_mat(A);

    // for (i = 0; i < A->size2; i++) {
    //     for (j = 0; j < A->size2; j++) {
    //       a = gsl_matrix_column (A, i);
    //       b = gsl_matrix_column (A, j);
    //       double cov = gsl_stats_covariance(a.vector.data, 
    //                                         a.vector.stride,
    //                                         b.vector.data, 
    //                                         b.vector.stride, 
    //                                         rsize);
    //       gsl_matrix_set (C, i, j, cov);
    //     }
    //   }

    // print_mat(C);

    return 0;
}


