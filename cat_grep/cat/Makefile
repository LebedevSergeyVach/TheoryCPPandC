CC = gcc

FLAGS = -std=c11 -Wall -Wextra -Werror -pedantic

CPPCHECK = cppcheck --enable=all --suppress=missingIncludeSystem
MEMORYLEAKS = MallocStackLogging=1 leaks -q -atExit --

OUT_FILE = s21_cat
BUILD_FILES = s21_cat.c s21_options_cat.c s21_process_cat_file.c ../common/error.c

TEST = test.txt -t -b -s

.PHONY = all clean

all: build

run: run_mac
build: build_cat
clean: clean_out

build_cat:
	@$(CC) $(FLAGS) $(BUILD_FILES) -o $(OUT_FILE)
	
run_mac:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@$(CPPCHECK) ./
	@$(MEMORYLEAKS) ./a.out $(TEST)
	@rm -rf a.out

run_win:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@./a.exe $(TEST)
	@rm -rf a.exe

run_arch:
	@clear
	@$(CC) $(BUILD_FILES)
	@./a.out $(TEST)
	@rm -rf a.out

clean_out:
	@rm -rf *.exe *.out
