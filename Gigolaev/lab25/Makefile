CC = g++
CFLAGS = -std=c++11 -Wall -Wextra -Wpedantic

all: program

program: program.o
	$(CC) $(CFLAGS) MyDeque.hpp MyDeque.o program.o -o program

program.o: program.cpp
	$(CC) $(CFLAGS) -c program.cpp -o program.o

MyDeque.o: MyDeque.cpp MyDeque.hpp
	$(CC) $(CFLAGS) -c MyDeque.cpp -o MyDeque.o

clean:
	rm -f *.o program