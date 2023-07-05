cmake_minimum_required(VERSION 3.25)
project(PED)

set(CMAKE_CXX_STANDARD 17)

add_executable(PED src/main.cpp lib/tcomplejo.cpp include/tcomplejo.h include/tvectorcom.h lib/tvectorcom.cpp include/tlistacom.h lib/tlistacom.cpp)
