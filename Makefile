CXX=g++ 
CXX_FLAGS=-c -Wall -std=c++11

default: clean all

all: main.o

clean: 
	rm -f ./*.o

figures.o: figures.cpp figures.hpp
	$(CXX) $(CXX_FLAGS) $<

main.o: main.cpp figures.o
	$(CXX) $(CXX_FLAGS) $<
