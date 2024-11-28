CC = gcc

FLAGS = -std=c11 -Wall -Wextra -Werror -pedantic

CPPCHECK = cppcheck --enable=all --suppress=missingIncludeSystem --check-level=exhaustive
MEMORYLEAKS = MallocStackLogging=1 leaks -q -atExit --

OUT_FILE = s21_grep
BUILD_FILES = s21_grep.c s21_options_grep.c s21_process_grep_file.c s21_read_patterns_from_file.c ../common/error.c

TEST = -i -n -f test/pattern test/*.txt

.PHONY = all clean

all: test clean

run: run_arch
build: build_grep
clean: clean_out
test: test_grep

build_grep:
	@$(CC) $(FLAGS) $(BUILD_FILES) -o $(OUT_FILE)
	
run_mac:
	@clear
	@$(CPPCHECK) ./
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@$(MEMORYLEAKS) ./a.out
	@rm -rf a.out

run_arch:
	@clear
	@$(CPPCHECK) ./
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@./a.out $(TEST)
	@rm -rf a.out

run_win:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@./a.exe $(TEST)
	@rm -rf a.exe

clean_out:
	@rm -rf *.exe *.out

test_grep:
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
	@./a.out -f test/pattern error.txt
	@rm -rf a.out

error_not_found_pattern:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@./a.out -f error *.txt
	@rm -rf a.out

error_pattern:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@./a.out -f test/error_pattern test/*.txt
	@rm -rf a.out

