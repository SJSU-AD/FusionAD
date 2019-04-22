#!/bin/bash
sudo apt install python-pip

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
sudo apt-get install libgsl2 libgsl-dev libgsl-dbg gsl-bin

pip install python-can

sudo apt-get install ros-kinetic-rosserial-python
sudo apt-get install ros-kinetic-rosserial-arduino
sudo apt-get install ros-kinetic-rosserial

sudo apt install ros-kinetic-robot-localization
sudo apt install ros-kinetic-velodyne

rosdep install --from-paths src --ignore-src -r -y
