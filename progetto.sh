#!/bin/bash

clear
echo "Cleaninig"
rm -r build
rm bin/Pgenerate_robot_path

echo "mkdir"
mkdir build/

echo "build"
cd build/
cmake ..
make

echo "Run"
echo ""
echo ""
echo ""
echo ""

cd ../bin

#./generate_robot_path > out1.txt

./generate_robot_path map.pgm
