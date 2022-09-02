CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -std=c11

SOURCE_DIR = .

all: s21_grep

test: s21_grep
	chmod 777 test.sh
	./test.sh

s21_grep: *.c s21_grep.h
	$(CC) $(CFLAGS) -c *.c
	$(CC) $(CFLAGS) *.o -o s21_grep

clean_all: s21_grep clean
	rm s21_grep
	rm log.txt

clean:
	@find . -name "*.o" -exec rm -f {} \;
	@find . -name "*.out" -exec rm -f {} \;
	@echo "Cleaning..."
	@echo "Sector clear :)"

style:
	python3 ../../materials/linters/cpplint.py --extensions=c *.c *.h 
