CC = gcc

FLAGS = -std=c11 -Wall -Wextra -Werror -pedantic
ADD_FLAGS = -fsanitize=address -fsanitize=leak -fsanitize=undefined -fsanitize=unreachable

CPPCHECK = cppcheck --enable=all --suppress=missingIncludeSystem --check-level=exhaustive
MEMORY_LEAKS = MallocStackLogging=1 leaks -q -atExit --
MEMORY_VALGRIND = valgrind --tool=memcheck --leak-check=yes -s

OUT_FILE = s21_grep
BUILD_FILES = s21_grep_main.c s21_options_grep.c s21_process_grep_file.c s21_read_patterns_from_file.c s21_read_and_combination_patterns.c ../common/error.c

TEST = -i -n -e "tab" -e "hello" -e "on" txt_test/*.txt

.PHONY = all clean

all: build

run: run_mac
s21_grep: build_grep
build: build_grep
clean: clean_out
test: test_grep
help: help_grep
clang: clang_format_i
clang_test: clang_format_n

build_grep:
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

help_grep:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES) -o $(OUT_FILE)
	@./$(OUT_FILE) --help
	@rm -rf $(OUT_FILE)

test_grep:
	@clear
	@$(CPPCHECK) ./
	@$(CC) $(FLAGS) $(ADD_FLAGS) $(BUILD_FILES)
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
	@./a.out -f txt_test/pattern error.txt
	@rm -rf a.out

error_not_found_pattern:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@./a.out -f error *.txt
	@rm -rf a.out

error_pattern:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@./a.out -f txt_test/error_pattern txt_test/*.txt
	@rm -rf a.out

clang_format_i:
	@clang-format -i *.c
	@clang-format -i *.h

clang_format_n:
	@clang-format -n *.c
	@clang-format -n *.h
