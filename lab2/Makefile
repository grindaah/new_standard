CC=g++

CFLAGS=-std=c++1y

all: mstring_test

mstring_test: my_string.o
	$(CC) $(CFLAGS) my_string.o my_string.test.cpp -o mstring_test

my_string.o: my_string.cpp my_string.h
	$(CC) $(CFLAGS) -c my_string.cpp

clean:
	rm -f *.o mstring_test
