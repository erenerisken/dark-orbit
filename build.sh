if ! command -v cmake &> /dev/null
then
    echo "cmake should be installed to build the project!"
    exit
fi

rm -r -f cmake_dir
mkdir cmake_dir

cmake CMakeLists.txt
make all

rm -r -f bin
mkdir bin
mv dark_orbit bin
mv run_tests bin

rm *.cmake
rm CMakeCache.txt
rm *.a
rm Makefile
rm *.cbp
rm test_*
rm CMakeFiles
rmdir cmake_dir

./bin/run_tests