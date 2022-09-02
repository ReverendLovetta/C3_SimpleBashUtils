CC = gcc

CFLAGS = -Wall -Werror -Wextra -g -std=c11

SOURCE_DIR = .

all: s21_cat

test: s21_cat
	chmod 777 test.sh
	./test.sh

s21_cat: *.c s21_cat.h
	$(CC) $(CFLAGS) -c *.c
	$(CC) $(CFLAGS) *.o -o s21_cat

clean_all: s21_cat clean
	rm s21_cat
	rm log.txt

clean:
	@find . -name "*.o" -exec rm -f {} \;
	@find . -name "*.out" -exec rm -f {} \;
	@echo "Cleaning..."
	@echo "Sector clear :)"

style:
	python3 ../../materials/linters/cpplint.py --extensions=c *.c *.h 
