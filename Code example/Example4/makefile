#
# C++ Assignemnt4 makefile
# Author: Xueni Fu
# Date: 14 April 2023
#

CXX = g++
CXXFLAGS = -W -Wall -Wsign-conversion -Werror -std=c++20
EXE = sort_ranges sort assignment4b assignment4a
SRCS = sort_ranges.cc sort.cc assignment4b.cc assignment4a.cc grid.cc person.cc 
DEPSA = assignment4.h person.h
DEPSB = grid.h assignment4.h person.h 
all:$(EXE)

sort_ranges:sort_ranges.cc
	$(CXX) -o $@ $^ $(CXXFLAGS)
sort:sort.cc
	$(CXX) -o $@ $^ $(CXXFLAGS)
assignment4b:assignment4b.o grid.o person.o
	$(CXX) -o $@ $^ $(CXXFLAGS)
assignment4a:assignment4a.o person.o
	$(CXX) -o $@ $^ $(CXXFLAGS)
assignment4b.o:assignment4b.cc grid.h $(DEPSB)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
assignment4a.o:assignment4a.cc $(DEPSA)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
grid.o:grid.cc $(DEPSB)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
person.o:person.cc $(DEPSA)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY:clean

clean:
	rm -f $(EXE) *.o 
