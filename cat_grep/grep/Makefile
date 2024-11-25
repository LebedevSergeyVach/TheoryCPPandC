CC = gcc

FLAGS = -std=c11 -Wall -Wextra -Werror -pedantic

CPPCHECK = cppcheck --enable=all --suppress=missingIncludeSystem --check-level=exhaustive
MEMORYLEAKS = MallocStackLogging=1 leaks -q -atExit --

OUT_FILE = s21_grep
BUILD_FILES = s21_grep.c s21_options_grep.c s21_process_grep_file.c ../common/error.c

TEST = -i -n "Привет, мир!" *.txt 

.PHONY = all clean

all: build clean

run: run_arch
build: build_grep
clean: clean_out

build_grep:
	@$(CC) $(FLAGS) $(BUILD_FILES) -o $(OUT_FILE)
	
run_mac:
	@clear
	@$(CPPCHECK) ./
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@$(MEMORYLEAKS) ./a.out
	@rm -rf a.out

run_win:
	@clear
	@$(CC) $(BUILD_FILES)
	@./a.exe $(TEST)
	@rm -rf a.exe

run_arch:
	@clear
	@$(CPPCHECK) ./
	@$(CC) $(BUILD_FILES)
	@./a.out $(TEST)
	@rm -rf a.out

clean_out:
	@rm -rf *.exe *.out
