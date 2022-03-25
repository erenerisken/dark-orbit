cmake_minimum_required(VERSION 3.21)
project(dark_orbit)

set(CMAKE_CXX_STANDARD 20)

include_directories("${PROJECT_SOURCE_DIR}/src/classes")
add_executable(
        dark_orbit
        src/main.cpp
        src/classes/Vector3.cpp
        src/classes/Vector3.h
        src/classes/RotationMatrix.cpp
        src/classes/RotationMatrix.h
        src/classes/Utilities.cpp
        src/classes/Utilities.h
        src/classes/Sphere.cpp
        src/classes/Sphere.h
        src/classes/Simulation.cpp
        src/classes/Simulation.h
        src/classes/Errors.cpp
        src/classes/Errors.h
)

add_executable(
        run_tests
        src/classes/Vector3.cpp
        src/classes/Vector3.h
        src/classes/RotationMatrix.cpp
        src/classes/RotationMatrix.h
        src/classes/Utilities.cpp
        src/classes/Utilities.h
        src/classes/Sphere.cpp
        src/classes/Sphere.h
        src/classes/Simulation.cpp
        src/classes/Simulation.h
        src/classes/Errors.cpp
        src/classes/Errors.h
        src/test/TestVector3.cpp
        src/test/TestVector3.h
        src/test/test.cpp src/test/TestSuite.cpp src/test/TestSuite.h src/test/TestSphere.cpp src/test/TestSphere.h src/test/TestRotationMatrix.cpp src/test/TestRotationMatrix.h)

