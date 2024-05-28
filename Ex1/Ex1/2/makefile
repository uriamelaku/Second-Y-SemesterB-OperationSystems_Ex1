CC = g++
AR = ar
CFLAGS =-g -Wall -std=c++11 -Werror -Wsign-conversion
AFLAGS =-rcs

.PHONY: all clean

all: Poisson

Poisson: main.o libPoisson.a
	$(CC) $(CFLAGS) main.o libPoisson.a -o Poisson -lm

libPoisson.a: poisson.o
	$(AR) $(AFLAGS) libPoisson.a poisson.o

poisson.o: poisson.cpp poisson.hpp
	$(CC) $(CFLAGS) -c poisson.cpp 

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp


clean:
	rm -f *.o *.a Poisson