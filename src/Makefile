CC              := gcc
FLAGS           := -Wall -Werror -Wextra -std=c11 -g
INC_DIRS        := -I.
TEST_FLAGS      := -lcheck -lm -lpthread
COV_FLAGS       := --coverage

ifeq ($(shell uname -s),Darwin) 
 TEST_FLAGS = $(shell pkg-config --cflags --libs check) 
endif

LIB_DIR         := func/
TESTS_DIR       := tests/
COV_DIR         := coverage_info/
OBJ_DIR         := object/
LIB_OBJ_DIR     := $(OBJ_DIR)$(LIB_DIR)
COV_OBJ_DIR     := $(COV_DIR)$(OBJ_DIR)

LIB_HEADER      := s21_math.h
LIB_SRCS        := $(addprefix $(LIB_DIR),s21_abs.c \
                                          s21_acos.c \
                                          s21_asin.c \
                                          s21_atan.c \
                                          s21_fabs.c \
                                          s21_ceil.c \
                                          s21_cos.c \
                                          s21_exp.c \
                                          s21_floor.c \
                                          s21_fmod.c \
                                          s21_log.c \
                                          s21_pow.c \
                                          s21_sin.c \
                                          s21_sqrt.c \
                                          s21_tan.c)

TEST_SRCS       := $(addprefix $(TESTS_DIR),test_main.c)


LIB_OBJS        := $(patsubst %.c,\
                              $(OBJ_DIR)%.o,\
                              $(LIB_SRCS))
COV_OBJS        := $(patsubst %.c,\
                              $(COV_OBJ_DIR)%.o,\
                              $(LIB_SRCS))

LIB_STATIC      := s21_math.a
TEST_EXEC       := test_main
COV_EXEC        := $(COV_DIR)test_cov

COV_INFO        := $(COV_DIR)s21_math.info
COV_REPORT      := $(COV_DIR)func/index.html

vpath %.c $(LIB_DIR)

.PHONY: all test clean

all: test gcov_report

s21_math.a: 
	$(TEST_SRCS)

test: $(TEST_SRCS) $(LIB_STATIC)
	$(CC) $(FLAGS) $(INC_DIRS) $^ $(TEST_FLAGS) -o $(TEST_EXEC)
	./$(TEST_EXEC)

gcov_report: $(TEST_SRCS) $(COV_OBJS)
	$(CC) $(FLAGS) $(INC_DIRS) $(COV_FLAGS) $^ $(TEST_FLAGS) -o $(COV_EXEC)
	@-./$(COV_EXEC)
	@gcov -f $(COV_EXEC) -o $(COV_DIR)
	@lcov -q -c -d $(COV_DIR) -o $(COV_INFO) --exclude "$(TESTS_DIR)*"
	@genhtml -q $(COV_INFO) -o $(COV_DIR)
	@open $(COV_REPORT)

$(LIB_STATIC): $(LIB_OBJS)
	@ar -rc $@ $^
	@ranlib $@

$(LIB_OBJ_DIR)%.o: %.c $(LIB_HEADER)
	@mkdir -p $(LIB_OBJ_DIR)
	$(CC) $(FLAGS) $(INC_DIRS) -c $< -o $@

$(COV_OBJ_DIR)%.o: %.c $(LIB_HEADER)
	@mkdir -p $(COV_OBJ_DIR)$(LIB_DIR)
	@$(CC) $(FLAGS) $(INC_DIRS) $(COV_FLAGS) -c $< -o $@

clean:
	@-rm -rf $(OBJ_DIR) $(LIB_STATIC) $(TEST_EXEC) $(COV_DIR)

valgrind: test
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --verbose --log-file=RESULT_VALGRIND.txt ./$(TEST_EXEC)

leaks: test
	CK_FORK=no leaks --atExit -- ./$(TEST_EXEC)

clang: 
	clang-format -n -style=Google s21_math.h func/*.c
