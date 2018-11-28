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

# install gtest
sudo apt-get install libgtest-dev  
cd /usr/src/gtest  
sudo cmake CMakeLists.txt  
sudo make  

sudo cp *.a /usr/lib  

sudo apt-get install ros-kinetic-joy
sudo apt-get install ros-kinetic-usb-cam
sudo pip install utm
<<<<<<< HEAD

=======
sudo apt-get install libgsl2 libgsl-dev libgsl-dbg gsl-bin
>>>>>>> b90c2815d158d8d3b3af00809b6008b9177db78d
