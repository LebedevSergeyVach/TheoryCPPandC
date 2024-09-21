CC=gcc
CFLAGS = -Wall -Werror -Wextra

MEMORYFLAGS = MallocStackLogging=1 leaks -q -atExit --

FILES_BUILDS = main.c array_io.c sort.c
OUTPUT_FILES = array

.PHONY: all clean

all: run

run: run_win

run_mac: $(FILES_BUILDS)
	@$(CC) $(CFLAGS) $(FILES_BUILDS) -o $(OUTPUT_FILES)
	@$(MEMORYFLAGS) ./$(OUTPUT_FILES)
	@rm $(OUTPUT_FILES)

run_win: $(FILES_BUILDS)
	@$(CC) $(CFLAGS) $(FILES_BUILDS) -o $(OUTPUT_FILES)
	@./$(OUTPUT_FILES)
	@rm $(OUTPUT_FILES)

clean:
	@rm -rf *.o *.out *.exe
