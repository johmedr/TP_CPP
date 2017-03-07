CXX=g++ 
CXX_FLAGS=-c -Wall -std=c++11
CXX_OUTPUT_FLAG=-o
CXX_OBJS=file.hpp figures.o main.o 

default: clean all 	

all: $(CXX_OBJS) 
	$(CXX) $(CXX_OUTPUT_FLAG) program $^

clean: 
	rm -f ./*.o

figures.o: figures.cpp figures.hpp
	$(CXX) $(CXX_FLAGS) $< $(CXX_OUTPUT_FLAG) $@

main.o: main.cpp file.hpp figures.hpp
	$(CXX) $(CXX_FLAGS) $< $(CXX_OUTPUT_FLAG) $@
