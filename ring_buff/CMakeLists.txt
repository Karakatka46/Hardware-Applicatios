cmake_minimum_required(VERSION 3.10)
project(RingBuffer)

set(CMAKE_CXX_STANDARD 20)
add_executable(ringBuff main.cpp ringBuff.cpp)
target_include_directories(ringBuff PRIVATE .)