#!/bin/bash

clear
echo "Cleaninig"
rm -r build
rm bin/Progetto_finale

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
./Progetto_finale