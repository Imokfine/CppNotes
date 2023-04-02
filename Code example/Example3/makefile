#
# C++ Assignemnt3 makefile
# Author: Xueni Fu
# Date: 20 March 2023
#

CXX = g++
CXXFLAGS = -W -Wall -Wsign-conversion -Werror -std=c++20
EXE = assignment3
SRCS = assignment3.cc logging.cc matrix_operations.cc
DEPS = logging.h matrix_operations.h matrix.h hpc_concepts.h 
all:$(EXE)

assignment3:assignment3.o logging.o matrix_operations.o
	$(CXX) -o $@ $^ $(CXXFLAGS)
assignment3.o:assignment3.cc $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)
matrix_operations.o:matrix_operations.cc matrix_operations.h matrix.h hpc_concepts.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)
logging.o:logging.cc logging.h
	$(CXX) -c -o $@ $< $(CXXFLAGS)

.PHONY:clean

clean:
	rm -f $(EXE) *.o
