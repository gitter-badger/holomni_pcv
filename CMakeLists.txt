cmake_minimum_required(VERSION 2.8)
project(holomni_pcv)
set(LIBNAME "holomni_pcv")

# Options
set(DCMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Compile in c++11 (not compiling yet)
OPTION(USE_C++11 "Use c++11" 0)


if(USE_C++11)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++0x")
	message("-- Using c++11")
endif(USE_C++11)


#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")


add_subdirectory(src)
    


