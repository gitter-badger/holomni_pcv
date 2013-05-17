## Process this file with automake to produce Makefile.in

#//////////////////////////////////////////////////////////////////

holomni_dir = $(top_srcdir)/src
matrix_dir = $(top_srcdir)/src/pr/include


libholomni_pcvincludedir = $(includedir)/holomni_pcv
libholomni_pcvinclude_HEADERS = \
	Pcv.h\
	Filter.h\
	Caster.h\
	Vehicle.h\
	Ctrl.h\
	Home.h\
	Params.h\
	Command.h\
	Status.h\
	Motion.h\
	PrGlobalDefn.h\
	Traj3.h\
	matrix/PrMatrix.h\
	matrix/PrVector.h
	

#///////////////////////////////////////////////////////////////////////////////////////////////////
lib_LTLIBRARIES = libholomni_pcv.la 
libholomni_pcv_la_LIBADD = -lyaml-cpp
libholomni_pcv_la_LDFLAGS = -version-info 1:0:0 -module
	
libholomni_pcv_la_CPPFLAGS = -g -Wl,-E -I$(matrix_dir) -I$(holomni_dir) -ffast-math -pipe


libholomni_pcv_la_SOURCES = \
	Pcv.cpp\
	Filter.cpp\
	Vehicle.cpp\
	Caster.cpp\
	Ctrl.cpp\
	Traj3.cpp\
	pr/src/matrix/PrMatrix.cpp\
	pr/src/matrix/PrVector.cpp

install: install-am
	mkdir /usr/local/include/holomni_pcv/matrix; mv /usr/local/include/holomni_pcv/PrMatrix.h /usr/local/include/holomni_pcv/matrix/; mv /usr/local/include/holomni_pcv/PrVector.h /usr/local/include/holomni_pcv/matrix/
	
#///////////////////////////////////////////////////////////////////////////////////////////////////

#bin_PROGRAMS = pcv_test
#pcv_test_SOURCES = pcv_test.cpp
#pcv_test_LDADD = -lholomni_pcv

#pcv_test_CPPFLAGS = -I$(matrix_dir) -I$(holomni_dir) -ffast-math 