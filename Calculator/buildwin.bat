rmdir /S /Q build
mkdir build
cd build
cmake .. -G "Visual Studio 15 2017 Win64" -T "Intel C++ Compiler 18.0"
cd ..
