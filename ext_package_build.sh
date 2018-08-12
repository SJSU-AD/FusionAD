#!/bin/bash

cd ~
sudo mkdir libsbp
cd libsbp
git clone https://github.com/swift-nav/libsbp
cd libsbp/c
mkdir build
cd build
cmake ../
make
sudo make install   # install headers and libraries into /usr/local

cd ~
git clone https://github.com/ktossell/libuvc
cd libuvc
mkdir build
cd build
cmake ..
make && sudo make install

cd ~
git clone 

sudo apt-get install ros-kinetic-joy

sudo pip install utm