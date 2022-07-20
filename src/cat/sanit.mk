SANIT_FLAGS = -fsanitize=address
CC = gcc
CFLAGS = -g -Werror -Wextra -Wall -std=c11
GCOV_FLAGS = -fPIC -fprofile-arcs -ftest-coverage
ifeq ($(shell uname -s),Darwin)
    CHECK_FLAGS = -lcheck -lm -lpthread
endif
ifeq ($(shell uname -s),Linux)
    CHECK_FLAGS = -lcheck -lm -lpthread -lrt -lsubunit
endif

TEST_DIR = ./tests
TEST_SRC := $(wildcard $(TEST_DIR)/*.c)
TEST_OBJS := $(TEST_SRC:$(TEST_DIR)/%.c=%.o)

SRC_DIR = .
SRC_SRC := $(wildcard $(SRC_DIR)/*.c)
SRC_OBJS := $(SRC_SRC:%.c=$(SRC_DIR)/%.o)

EXEC_GCOV = $(TEST_OBJS:%.o=%.out) 

LIB_NAME = s21_math.a
INCL_LIB = -L.

all: $(SRC_OBJS) $(EXEC_GCOV) execute 

$(EXEC_GCOV): %.out: %.o $(TEST_OBJS)
	$(CC) $(TEST_DIR)/$< $(SRC_DIR)/*.o -o $(TEST_DIR)/$@ $(CHECK_FLAGS) $(SANIT_FLAGS)
	
$(TEST_OBJS): %.o : $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) -o $(TEST_DIR)/$@ -c $< $(SANIT_FLAGS)

$(SRC_OBJS): %.o : $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -o $(SRC_DIR)/$@ -c $< $(SANIT_FLAGS)

execute: $(EXEC_GCOV)
	@for test in $^; do \
		./tests/$${test}; \
		echo; \
	done

%:
	@true
