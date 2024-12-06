CC = gcc

FLAGS = -std=c11 -Wall -Wextra -Werror -pedantic
ADD_FLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=unreachable

CPPCHECK = cppcheck --enable=all --suppress=missingIncludeSystem --check-level=exhaustive
MEMORY_LEAKS = MallocStackLogging=1 leaks -q -atExit --
MEMORY_VALGRIND = valgrind --tool=memcheck --leak-check=yes

OUT_FILE = s21_cat
BUILD_FILES = s21_cat_main.c s21_options_cat.c s21_process_cat_file.c ../common/error.c

TEST = txt_test/test.txt -s -n -t -v -e

.PHONY = all clean

all: s21_cat

run: run_mac
s21_cat: build_cat
build: build_cat
clean: clean_out
test: test_cat
help: help_cat
clang: clang_format_i
clang_test: clang_format_n

build_cat:
	@$(CC) $(FLAGS) $(BUILD_FILES) -o $(OUT_FILE)
	
run_mac:
	@clear
	@$(CPPCHECK) ./
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@$(MEMORY_LEAKS) ./a.out $(TEST)
	@rm -rf a.out

run_arch:
	@clear
	@$(CPPCHECK) ./
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@$(MEMORY_VALGRIND) ./a.out $(TEST)
	@rm -rf a.out

run_win:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@./a.exe $(TEST)
	@rm -rf a.exe

clean_out:
	@rm -rf *.exe *.out $(OUT_FILE)

help_cat:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES) -o $(OUT_FILE)
	@./$(OUT_FILE) --help
	@rm -rf $(OUT_FILE)

test_cat:
	@clear
	@$(CPPCHECK) ./
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@./a.out $(TEST)
	@rm -rf a.out

error_flag:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@./a.out $(TEST) -q
	@rm -rf a.out

error_file:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@./a.out error.txt
	@rm -rf a.out

clang_format_i:
	@clang-format -i *.c
	@clang-format -i *.h

clang_format_n:
	@clang-format -n *.c
	@clang-format -n *.h
