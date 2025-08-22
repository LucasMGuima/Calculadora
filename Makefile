CC = gcc
CFLAGS = -Wall -Wextra -I.
LDFLAGS = -lm

SRC = calc.c src/stack.c src/tokens.c src/operations.c
OBJ = $(SRC:.c=.o)
TARGET = calculadora.exe

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $@ $(SRC) $(LDFLAGS)

clean:
	rm -f $(TARGET) src/*.o *.o

.PHONY: all clean