CC = gcc

FLAGS = -Wall -Wextra -Werror

CPPCHECK = cppcheck --enable=all --suppress=missingIncludeSystem
MEMORYLEAKS = MallocStackLogging=1 leaks -q -atExit --

OUT_FILE = s21_cat
BUILD_FILES = s21_cat.c ../common/common.c ../common/error.c

.PHONY = all clean

all: build

run: run_win
build: build_cat

clean: clean_out


build_cat:
	@$(CC) $(FLAGS) $(BUILD_FILES) -o $(OUT_FILE)
	
run_mac:
	@clear
	@$(CC) $(FLAGS) $(BUILD_FILES)
	@$(CPPCHECK) ./
	@$(MEMORYLEAKS) ./a.out
	@rm -rf a.out

run_win:
	@clear
	@$(CC) $(BUILD_FILES)
	@./a.exe test.txt -t -b -s
	@rm -rf a.exe

run_arch:
	@clear
	@$(CC) $(BUILD_FILES)
	@./a.out -n test.txt
	@rm -rf a.out

clean_out:
	@rm -rf *.exe *.out
