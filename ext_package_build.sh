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


sudo apt-get install ros-kinetic-joy

sudo pip install utm