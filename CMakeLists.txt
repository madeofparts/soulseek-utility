cmake_minimum_required(VERSION 3.15)
project(SoulseekManager VERSION 1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

Include(FetchContent)
FetchContent_Declare(
  Catch2
  GIT_REPOSITORY https://github.com/catchorg/Catch2.git
  GIT_TAG        v3.15.3 # or a later release
)
FetchContent_MakeAvailable(Catch2)
# These tests need their own main
add_executable(run_test test/test.cpp)
target_link_libraries(run_test PRIVATE Catch2::Catch2WithMain)

list(APPEND CMAKE_MODULE_PATH ${catch2_SOURCE_DIR}/extras)
include(CTest)
include(Catch)
catch_discover_tests(run_test)

add_executable(my_app
  src/main.cpp)

target_compile_options(my_app PRIVATE -Wall -Wextra -std=c++20)
