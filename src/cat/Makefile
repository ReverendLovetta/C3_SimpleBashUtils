#UNAME = $(shell uname -s)
#CHECK_FLAGS = -lcheck -lm -lpthread
ifeq ($(shell uname -s),Darwin)
    CHECK_FLAGS = -lcheck -lm -lpthread
endif
ifeq ($(shell uname -s),Linux)
    CHECK_FLAGS = -lcheck -lpthread -lrt -lm -lsubunit
endif

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g -std=c11 -lm
GCOV_FLAGS = -fPIC -fprofile-arcs -ftest-coverage

LIB_OUT = s21_cat.a
LIB_NAME = s21_cat.a
INCL_LIB = -L.

SOURCE_DIR = .
LIB_SRC := $(wildcard $(SOURCE_DIR)/*.c)
LIB_OBJS := $(LIB_SRC:$(SOURCE_DIR)/%.c=%.o)

TEST_DIR = ./tests
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS := $(TEST_SRC:$(TEST_DIR)/%.c=%.o)

TEST_EXEC = $(TEST_OBJS:%.o=%.out)

S21_CAT = s21_cat.a

.PHONY: all


all: $(TEST_OBJS) $(LIB_OBJS) s21_cat.a

$(LIB_OBJS): %.o : $(SOURCE_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TEST_OBJS): %.o : $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@ 

$(TEST_EXEC): %.out: %.o $(TEST_OBJS)
	$(CC) $< $(INCL_LIB) $(LIB_NAME) -o $@ $(CHECK_FLAGS)

.PHONY: s21_cat.a
s21_math.a: $(LIB_OBJS) 
	@ar rc $(LIB_OUT) $(LIB_OBJS)
	@ranlib $(LIB_OUT)

.PHONY: test
test: s21_math.a build

build: $(TEST_EXEC)
	@for test in $^; do \
		./$${test}; \
		echo; \
	done

.PHONY: gcov_report
gcov_report: clean
	$(MAKE) -f gcov.mk

.PHONY: sanitizer
sanitizer: clean_all
	$(MAKE) -f sanit.mk

.PHONY: clean
clean:
	@find . -name "*.o" -exec rm -f {} \;
	@find . -name "*.out" -exec rm -f {} \;
	@find . -name "*.gcov" -exec rm -f {} \;
	@find . -name "*.gcda" -exec rm -f {} \;
	@find . -name "*.gcno" -exec rm -f {} \;
	@rm -rf OUT
	@rm -f cover.info
	@echo "Cleaning..."
	@echo "Operation complete :)"

.PHONY: clean_lib
clean_lib:
	@find . -name "*.a" -exec rm -f {} \;

.PHONY: clean_all
clean_all: clean_lib clean

.PHONY: style
style:
	python3 ../materials/linters/cpplint.py --extensions=c *.c *.h tests/*.c 

