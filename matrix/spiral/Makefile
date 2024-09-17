CC = gcc
CFLAGS = -Wall -Wextra -Werror

BUILD = ../build
MEMORY_FLAGS = MallocStackLogging=1 leaks -q -atExit --
CPP = cppcheck --enable=all --suppress=missingIncludeSystem *.c

CLANGN = clang-format -n *.c
CLANGI = clang-format -n *.c

FILES_BUILD_RUN = spiral.c
OUT_FILES_RUN = run.out

.PHONY: all clean

all: run clean

clean:
	@rm -rf *.o

run: $(FILES_BUILD_RUN)
	@$(CPP)
	@$(CLANGN)
	@$(CC) $(CFLAGS) $(CFLAGCLOGGER) $(FILES_BUILD_RUN) -o $(OUT_FILES_RUN)
	@$(MEMORY_FLAGS) ./$(OUT_FILES_RUN)
	@rm $(OUT_FILES_RUN)

remove:
	@rm -rf *.out
	@rm -rf ../build/*.out
