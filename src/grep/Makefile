CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -std=c11 -lm

SOURCE_DIR = .

all: *.c s21_grep.h
	$(CC) $(CFLAGS) -c *.c
	$(CC) $(CFLAGS) *.o -o s21_grep

clean:
	@find . -name "*.o" -exec rm -f {} \;
	@find . -name "*.out" -exec rm -f {} \;
	@echo "Cleaning..."
	@echo "Sector clear :)"