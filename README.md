Require mingw32-make, gcc, g++

mkdir build && cd build

cmake -G "MinGW Makefiles" ../

mingw32-make all

mingw32-make install