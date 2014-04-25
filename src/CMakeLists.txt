cmake_minimum_required(VERSION 2.8)
project(holomni_pcv)
set(LIBNAME "holomni_pcv")

find_package(YamlCpp)
include_directories(${YAMLCPP_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/matrix)

file(GLOB sources ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
file(GLOB matrix_srcs ${CMAKE_CURRENT_SOURCE_DIR}/matrix/*.cpp)
list(APPEND sources ${matrix_srcs})


add_library(${LIBNAME} SHARED ${sources})
target_link_libraries(${LIBNAME} ${YAMLCPP_LIBRARY})

install(TARGETS ${LIBNAME} DESTINATION lib)
install(FILES ${headers} DESTINATION include/${PROJECT_NAME})

