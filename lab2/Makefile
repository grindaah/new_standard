CC=g++

CFLAGS=-std=c++1y -g -Wall

all: mstring_test wrapper_test marray_test

mstring_test: my_string.o
	$(CC) $(CFLAGS) my_string.o my_string.test.cpp -o mstring_test

marray_test: my_array.o my_string.o
	$(CC) $(CFLAGS) my_array.o my_string.o my_array.test.cpp -o marray_test

wrapper_test: my_string.o
	$(CC) $(CFLAGS) my_string.o wrap_any.test.cpp -o wrap_test

my_string.o: my_string.cpp my_string.h
	$(CC) $(CFLAGS) -c my_string.cpp

my_array.o: my_array.cpp my_array.h
	$(CC) $(CFLAGS) -c my_array.cpp

clean:
	rm -f *.o mstring_test wrap_test marray_test
