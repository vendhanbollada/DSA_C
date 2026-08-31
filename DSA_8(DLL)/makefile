CC = gcc
CFLAGS = -Wall -Wextra

TARGET = main

$(TARGET): MainProgDLL_2.o DLLFunc.o
	$(CC) $(CFLAGS) -o $(TARGET) MainProgDLL_2.o DLLFunc.o

MainProgDLL_2.o: MainProgDLL_2.c DLList_2.h
	$(CC) $(CFLAGS) -c MainProgDLL_2.c

DLLFunc.o: DLLFunc.c DLList_2.h
	$(CC) $(CFLAGS) -c DLLFunc.c

clean:
	rm -f $(TARGET) *.o