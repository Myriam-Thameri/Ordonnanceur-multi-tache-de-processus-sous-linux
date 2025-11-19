CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = fifo
OBJECTS = main.o processus.o algorithmes/fifo.o

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(TARGET)

main.o: main.c processus.h algorithmes/fifo.h
	$(CC) $(CFLAGS) -c main.c

processus.o: processus.c processus.h
	$(CC) $(CFLAGS) -c processus.c

algorithmes/fifo.o: algorithmes/fifo.c algorithmes/fifo.h processus.h
	$(CC) $(CFLAGS) -c algorithmes/fifo.c -o algorithmes/fifo.o

clean:
	rm -f *.o algorithmes/*.o $(TARGET)

run: $(TARGET)
	./$(TARGET)

.PHONY: all clean run