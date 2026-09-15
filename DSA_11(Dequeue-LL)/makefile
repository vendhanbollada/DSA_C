CC = gcc
CFLAGS = -Wall -Wextra -g

all: DequeList.o DequeListMain.o 
	$(CC) $(CFLAGS) $^ -o $@
DequeList.o:DequeList.c DequeList.h 
	$(CC) $(CFLAGS) -c $< -o $@
DequeListMain.o:DequeListMain.c DequeList.h
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	rm -f *.o all

