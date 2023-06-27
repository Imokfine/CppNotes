#
# C++ Assignemnt5 makefile
# Author: Xueni Fu
# Date: 14 May 2023
#

CXX = g++
CXXFLAGS = -pthread -W -Wall -Wsign-conversion -Werror -std=c++20
CXXFLAGS2 = -fconcepts -std=c++17
EXE = assignment5c assignment5b assignment5a
SRCS = assignment5c.cc assignment5b.cc assignment5a.cc ConvexHull.cc point.cc 
DEPS = ConvexHull.h point.h

all:$(EXE)

assignment5c:assignment5c.o ConvexHull.o point.o
	$(CXX) -o $@ $^ $(CXXFLAGS) -lboost_mpi -lboost_serialization -lmpi 
assignment5b:assignment5b.o ConvexHull.o point.o
	$(CXX) -O1 -o $@ $^ $(CXXFLAGS) -lboost_mpi -lboost_serialization -lmpi 
assignment5a:assignment5a.o 
	$(CXX) -o $@ $^ $(CXXFLAGS)

assignment5c.o:assignment5c.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) -lboost_mpi -lboost_serialization  
assignment5b.o:assignment5b.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS) -lboost_mpi -lboost_serialization  
assignment5a.o:assignment5a.cc 
	$(CXX) -c -o $@ $< $(CXXFLAGS)
ConvexHull.o:ConvexHull.cc point.h
	$(CXX) -c -o $@ $< $(CXXFLAGS) 
point.o:point.cc point.h
	$(CXX) -c -o $@ $< $(CXXFLAGS) -lboost_mpi -lboost_serialization

.PHONY:clean

clean:
	rm -f $(EXE) *.o *.txt 
