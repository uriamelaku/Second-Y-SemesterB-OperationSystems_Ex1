CXX=g++ -g -Wall 
CXXFLAGS=-std=c++11 -Werror -Wsign-conversion

all: D_Poisson

D_Poisson: main.o libpoisson.so
	$(CXX) $(CXXFLAGS) -o D_Poisson main.o -L. -lpoisson

libpoisson.so: poisson.cpp poisson.hpp
	$(CXX) $(CXXFLAGS) -fPIC -shared poisson.cpp -o libpoisson.so

main.o: main.cpp poisson.hpp
	$(CXX) $(CXXFLAGS) -c main.cpp -o main.o

clean:
	rm -f D_Poisson libpoisson.so main.o

.PHONY: all clean