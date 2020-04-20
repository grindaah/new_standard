CC = g++

CFLAGS = -std=c++1y

TARGET = lab1
SOURCE = ConsoleApp.cpp

CHECK = check

all: $(TARGET)

$(TARGET) : ConsoleApp.cpp
	$(CC) $(CFLAGS) $(SOURCE) -o $(TARGET)

$(CHECK) : unique_vector.test.cpp
	$(CC) $(CFLAGS) unique_vector.test.cpp -o $(CHECK)

clean: $(TARGET)
	rm -f $(TARGET) $(CHECK)
