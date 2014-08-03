cmake_minimum_required(VERSION 2.8)
project(holomni-pcv)
set(LIBNAME "holomni_pcv")
SET(MAJOR_VERSION "1")
SET(MINOR_VERSION "2")
SET(PATCH_VERSION "2")
set(M3CORE_VERSION
  ${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION})
  
# Options
#set(DCMAKE_BUILD_TYPE "Release")

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -Wno-reorder")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -ggdb")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Compile in c++11
OPTION(C++11 "Use c++11" 0)


if(C++11)
	set(CMAKE_CXX_FLAGS "-std=c++0x")
	message("-- Using c++11")
endif(C++11)

## Enable PPA upload
OPTION(ENABLE_PPA "Enable PPA creation" FALSE)
OPTION(UPLOAD_PPA "Enable PPA upload" FALSE)
OPTION(CHANGELOG_MESSAGE "Set the changelog message" OFF)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/Modules/")


add_subdirectory(src)

######## Debian #######

#### Package Generation
execute_process (
  COMMAND          /usr/bin/dpkg --print-architecture
  OUTPUT_VARIABLE  CPACK_DEBIAN_PACKAGE_ARCHITECTURE
  RESULT_VARIABLE  EXECUTE_RESULT
  OUTPUT_STRIP_TRAILING_WHITESPACE
  ERROR_QUIET
)
if(EXECUTE_RESULT)
  message(STATUS "dpkg not found: No package generation.")
else()
IF(EXISTS "${CMAKE_ROOT}/Modules/CPack.cmake")
INCLUDE(InstallRequiredSystemLibraries)
message(STATUS "Debian architecture: ${CPACK_DEBIAN_PACKAGE_ARCHITECTURE}")

#SET(CPACK_SET_DESTDIR "on")
#SET(CPACK_PACKAGING_INSTALL_PREFIX "/tmp")
SET(CPACK_GENERATOR "DEB")

SET(CPACK_PACKAGE_DESCRIPTION "Holomni PCV : control the holomni wheels")
SET(CPACK_PACKAGE_DESCRIPTION_SUMMARY "This package is used to control the B1 base on the Meka robot")

SET(CPACK_PACKAGE_VENDOR "Meka Robotics LLC, Inria, Ensta ParisTech")
SET(CPACK_DEBIAN_PACKAGE_MAINTAINER "Antoine Hoarau <hoarau.robotics@gmail.com>")
SET(CPACK_PACKAGE_CONTACT "Antoine Hoarau <hoarau.robotics@gmail.com>")
set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "https://bitbucket.org/ensta/holomni_pcv")
SET(CPACK_PACKAGE_VERSION_MAJOR "${MAJOR_VERSION}")
SET(CPACK_PACKAGE_VERSION_MINOR "${MINOR_VERSION}")
SET(CPACK_PACKAGE_VERSION_PATCH "${PATCH_VERSION}")
SET(CPACK_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${MAJOR_VERSION}.${MINOR_VERSION}.${CPACK_PACKAGE_VERSION_PATCH}")
SET(CPACK_SOURCE_PACKAGE_FILE_NAME "${CMAKE_PROJECT_NAME}_${MAJOR_VERSION}.${MINOR_VERSION}.${CPACK_PACKAGE_VERSION_PATCH}")

set(CPACK_STRIP_FILES TRUE)
set(PPA_DEBIAN_VERSION "0ubuntu1")
#dependencies for this service menu
set(CPACK_DEBIAN_PACKAGE_BUILD_DEPENDS cmake bzr git pkg-config devscripts libyaml-cpp-dev dh-make libboost-dev)
set(CPACK_DEBIAN_PACKAGE_DEPENDS libyaml-cpp-dev)
#SET(CPACK_DEBIAN_PACKAGE_DEPENDS "python2.7,swig,moc,libeigen3-dev,libprotobuf-dev,protobuf-compiler,libboost-dev,python-dev,python-protobuf,python-matplotlib,python-yaml,python-gnuplot,python-scipy,python-sip-dev,python-sip")
 
set(DPUT_HOST hoarau-robotics)
set(CPACK_DEBIAN_UPDATE_CHANGELOG TRUE)
#SET(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
#SET(CPACK_DEBIAN_PACKAGE_SECTION "libraries")
#SET(CPACK_DEBIAN_ARCHITECTURE ${CMAKE_SYSTEM_PROCESSOR})
 
#SET(CPACK_COMPONENTS_ALL Libraries ApplicationData)
INCLUDE(CPack)
if(ENABLE_PPA OR UPLOAD_PPA)
    set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "any") # can be build on any system
    include(UploadPPA)
endif()

ENDIF(EXISTS "${CMAKE_ROOT}/Modules/CPack.cmake")
endif()
