CC = gcc
CFLAGS = -Wall -Wextra -g

TARGET = app
OBJS = CCL.o MainCircularSLL2.o
HEADERS = CircularList2.h

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c $(HEADERS)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJS)