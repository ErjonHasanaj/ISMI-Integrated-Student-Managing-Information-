CC = gcc
CFLAGS = -Wall -g -I.

# List of source files
SRCS = main.c add_student.c find_student.c manage_student.c csv_export.c utilities.c

# List of object files
OBJS = $(SRCS:.c=.o)

# Target executable
TARGET = sims

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ $(CFLAGS)

%.o: %.c
	$(CC) -c -o $@ $< $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJS)
