# Makefile for homGeneMapping

include ../../../common.mk

CXX ?= g++

# Notes: - "-Wno-sign-compare" eliminates a high number of warnings (see footnote below). Please adopt
#          a strict signed-only usage strategy to avoid mistakes since we are not warned about this.
#        - The order of object files in $(OBJS) IS IMPORTANT (see lldouble.hh)
CXXFLAGS := -Wall -Wno-sign-compare -ansi -pedantic -std=c++0x -pthread -O2 ${CXXFLAGS}

INCLS	+= -I../include
OBJS	= gene.o genome.o

# set SQLITE = false in common.mk to disable the usage of the SQLite library, option --dbaccess will not be available
# set BOOST = false in common.mk to disable the usage of the Boost graph library, the option --printHomologs will not be available
BOOST ?= true

ifeq (,$(findstring $(COMPGENEPRED),0 false False FALSE)) # if COMPGENEPRED is not defined or not contains 0, false, False or FALSE
# comment this flag to disable database access for retrieval of hints, the option --dbaccess will not be available
	SQLITE ?= true
endif

ifeq (,$(findstring $(BOOST),0 false False FALSE)) # if BOOST is not defined or not contains 0, false, False or FALSE
	CPPFLAGS += -DBOOST
	INCLS   += $(INCLUDE_PATH_BOOST) # set boost include path in INCLUDE_PATH_BOOST, if boost is not installed system-wide
	LDFLAGS += $(LIBRARY_PATH_BOOST) # set boost library path in LIBRARY_PATH_BOOST, if boost is not installed system-wide
endif

ifneq (,$(findstring $(SQLITE),1 true True TRUE)) # if SQLITE is defined and contains 1, true, True or TRUE
	CPPFLAGS += -DM_SQLITE
	INCLS    += $(INCLUDE_PATH_SQLITE)
	LDFLAGS  += $(LIBRARY_PATH_SQLITE)
	LDLIBS  += -lsqlite3 # add the sqlite library path here, if sqlite is not install system-wide
	OBJS    += sqliteDB.o
endif

.PHONY: all clean

all: homGeneMapping

homGeneMapping: main.cc $(OBJS)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(LDFLAGS) $(INCLS) -o $@ $^ $(LDLIBS)
	mkdir -p ../../../bin/
	cp -f homGeneMapping ../../../bin/homGeneMapping

$(OBJS): %.o: %.cc
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) $(INCLS) -c $<

clean:
	rm -f homGeneMapping $(OBJS)
	rm -f ../../../bin/homGeneMapping

main.o : \
	../include/genome.hh \
	../include/projectio.hh \
	main.cc

gene.o : \
	../include/gene.hh \
	../include/projectio.hh \
	gene.cc

genome.o : \
	../include/genome.hh \
	../include/bitmasking.hh \
	../include/gene.hh \
	genome.cc

sqliteDB.o: \
	../include/sqliteDB.hh \
	sqliteDB.cc
