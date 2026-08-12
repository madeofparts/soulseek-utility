cmake_minimum_required(VERSION 3.15)
project(SoulseekManager VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_app
  src/main.cpp)

target_compile_options(my_app PRIVATE -Wall -Wextra -std=c++20)
