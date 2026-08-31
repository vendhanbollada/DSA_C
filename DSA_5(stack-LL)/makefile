CC = gcc
FLAGS = -Wextra -Wall -g 

app: StackList.o MainProgStack.o
	$(CC) $(FLAGS) $^ -o $@
StackList.o:StackList.c StackList.h
	$(CC) $(FLAGS) -c $< -o $@
MainProgStack.o:MainProgStack.c
	$(CC) $(FLAGS) -c $< -o $@
clean:
	rm -f *.o app