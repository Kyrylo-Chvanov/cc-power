cmake_minimum_required(VERSION 3.28) 
project(power)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "-Wall -Wextra")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(power
  ./src/main.cpp
  ./src/args.cpp
  ./src/basic.cpp
  ./src/complex.cpp
)

target_include_directories(power PRIVATE ./include)
target_link_libraries(power -static)

