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
)

add_executable(
        test_algebraic_operations
        src/test/algebraic_operations.cpp
        src/classes/Vector3.cpp
        src/classes/Vector3.h
        src/classes/RotationMatrix.cpp
        src/classes/RotationMatrix.h
        src/classes/Utilities.cpp
        src/classes/Utilities.h
        src/classes/Sphere.cpp
        src/classes/Sphere.h
)

add_executable(
        test_simulation_logic
        src/test/simulation_logic.cpp
        src/classes/Vector3.cpp
        src/classes/Vector3.h
        src/classes/RotationMatrix.cpp
        src/classes/RotationMatrix.h
        src/classes/Utilities.cpp
        src/classes/Utilities.h
        src/classes/Sphere.cpp
        src/classes/Sphere.h
)
