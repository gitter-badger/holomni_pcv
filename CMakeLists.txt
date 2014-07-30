cmake_minimum_required(VERSION 2.8)
project(holomni_pcv)
set(LIBNAME "holomni_pcv")
SET(MAJOR_VERSION "1")
SET(MINOR_VERSION "1")
SET(PATCH_VERSION "0")
set(M3CORE_VERSION
  ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})
  
# Options
set(DCMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Compile in c++11 (not compiling yet)
OPTION(C++11 "Use c++11" 0)


if(C++11)
	set(CMAKE_CXX_FLAGS "-Wall -std=c++0x")
	message("-- Using c++11")
endif(C++11)


#set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")


add_subdirectory(src)


######## Debian #######


IF(EXISTS "${CMAKE_ROOT}/Modules/CPack.cmake")
INCLUDE(InstallRequiredSystemLibraries)
 
SET(CPACK_SET_DESTDIR "on")
SET(CPACK_PACKAGING_INSTALL_PREFIX "/tmp")
SET(CPACK_GENERATOR "DEB")

SET(CPACK_PACKAGE_DESCRIPTION "Holomni PCV : control the holomni wheels")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "This package is used to control the B1 base on the Meka robot")
SET(CPACK_PACKAGE_VENDOR "Antoine Hoarau")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Antoine Hoarau <hoarau.robotics@gmail.com>")
SET(CPACK_PACKAGE_CONTACT "hoarau.robotics@gmail.com")
SET(CPACK_PACKAGE_VERSION_MAJOR "${MAJOR_VERSION}")
SET(CPACK_PACKAGE_VERSION_MINOR "${MINOR_VERSION}")
SET(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")
SET(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${MAJOR_VERSION}.${MINOR_VERSION}.${CPACK_PACKAGE_VERSION_PATCH}")
SET(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${MAJOR_VERSION}.${MINOR_VERSION}.${CPACK_PACKAGE_VERSION_PATCH}")
 
#dependencies for this service menu
#SET(CPACK_DEBIAN_PACKAGE_DEPENDS "python2.7,swig,moc,libeigen3-dev,libprotobuf-dev,protobuf-compiler,libboost-dev,python-dev,python-protobuf,python-matplotlib,python-yaml,python-gnuplot,python-scipy,python-sip-dev,python-sip")
 
SET(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
SET(CPACK_DEBIAN_PACKAGE_SECTION "libraries")
SET(CPACK_DEBIAN_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})
 
#SET(CPACK_COMPONENTS_ALL Libraries ApplicationData)
INCLUDE(CPack)
 
ENDIF(EXISTS "${CMAKE_ROOT}/Modules/CPack.cmake")
