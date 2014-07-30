#cmake_minimum_required(VERSION 2.8)
#project(holomni_pcv)
#set(LIBNAME "holomni_pcv")

find_package(PkgConfig REQUIRED)
#find_package(YamlCpp  REQUIRED)
pkg_check_modules(YAMLCPP REQUIRED yaml-cpp<=0.5)
if(NOT ${YAMLCPP_VERSION} VERSION_LESS "0.5")
add_definitions(-DHAVE_NEW_YAMLCPP)
endif(NOT ${YAMLCPP_VERSION} VERSION_LESS "0.5")
link_directories(${YAMLCPP_LIBRARY_DIRS})

include_directories(${YAMLCPP_INCLUDE_DIRS} ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_CURRENT_SOURCE_DIR}/matrix)

file(GLOB sources 
"${CMAKE_CURRENT_SOURCE_DIR}/*.cpp"
"${CMAKE_CURRENT_SOURCE_DIR}/matrix/*.cpp")

file(GLOB headers ${CMAKE_CURRENT_SOURCE_DIR}/*.h)
file(GLOB matrix_headers ${CMAKE_CURRENT_SOURCE_DIR}/matrix/*.h)


add_library(${LIBNAME} SHARED ${sources})
target_link_libraries(${LIBNAME} ${YAMLCPP_LIBRARIES})

install(TARGETS ${LIBNAME} DESTINATION lib COMPONENT library)
install(FILES ${headers} DESTINATION include/${PROJECT_NAME})
install(FILES ${matrix_headers} DESTINATION include/${PROJECT_NAME}/matrix)

