# Specify the minimum required version of CMake for this project. 
cmake_minimum_required(VERSION 3.14)

project(AUT_AP_2024_Spring_HW4)

# Set the C++ standard to C++23 and make it a required standard.
# If the compiler does not support C++23, CMake will produce an error.
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(GTest REQUIRED)
find_package(OpenSSL REQUIRED)

include_directories(include/)

add_executable(main
        src/main.cpp
        src/crypto.cpp
        src/unit_test.cpp
        src/message.cpp
        src/user.cpp
        src/server.cpp
        include/TextMessage.h
        include/VoiceMessage.h
)

# Set compiler flags for C++.
# -Wall, -Wextra, -Werror, and -Wpedantic are used for stricter warnings and error handling.
# Add -Wno-deprecated-declarations to suppress warnings for deprecated functions.
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Werror -Wpedantic -Wno-deprecated-declarations")

# Set compiler flags specific to the Release build type.
# -O3 enables high-level optimizations.
set(CMAKE_CXX_FLAGS_RELEASE "-O3 ${CMAKE_CXX_FLAGS_RELEASE}")

target_link_libraries(main
        GTest::GTest
        GTest::Main
        OpenSSL::SSL
)
