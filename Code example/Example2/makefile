# 
# C++ Assignemnt2 makefile
# Author: Xueni Fu
# Date: 22 Feb 2023
#

CXX = g++
CXXFLAGS = -W -Wall -std=c++17
EXE = assignment2a assignment2b
DEPS = instruments.h portfolio.h

all:$(EXE)

assignment2a:assignment2a.cc
	$(CXX) -o $@ $^ $(CXXFLAGS)
assignment2b:assignment2b.o portfolio.o
	$(CXX) -o $@ $^ $(CXXFLAGS)
assignment2b.o:assignment2b.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
portfolio.o:portfolio.cc portfolio.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)


.PHONY:clean

clean:
	rm -f $(EXE) *.o
