CC = gcc
CFLAGS = -Wall -Wextra -Werror

BUILD = ../build
MEMORY_FLAGS = MallocStackLogging=1 leaks -q -atExit --
CPP = cppcheck --enable=all --suppress=missingIncludeSystem *.c

FILES_BUILD_STATE_SORT = state_sort.c
OUT_FILES_STATE_SORT = Quest_1

FILES_BUILD_STATE_SEARCH = state_search.c
OUT_FILES_STATE_SEARCH = Quest_2

FILES_BUILD_STATE_CLEAR = clear_state.c
OUT_FILES_STATE_CLEAR = Quest_3

FILES_BUILD_RUN = clear_state.c
OUT_FILES_RUN = run

.PHONY: all clean

all: state_sort state_search clear_state clean

state_sort: $(FILES_BUILD_STATE_SORT)
	@$(CC) $(CFLAGS) $(FILES_BUILD_STATE_SORT) -o $(OUT_FILES_STATE_SORT)
	@mkdir -p $(BUILD)
	@mv $(OUT_FILES_STATE_SORT) $(BUILD)

state_search: $(FILES_BUILD_STATE_SEARCH)
	@$(CC) $(CFLAGS) $(FILES_BUILD_STATE_SEARCH) -o $(OUT_FILES_STATE_SEARCH)
	@mkdir -p $(BUILD)
	@mv $(OUT_FILES_STATE_SEARCH) $(BUILD)

clear_state: $(FILES_BUILD_STATE_CLEAR)
	@$(CC) $(CFLAGS) $(FILES_BUILD_STATE_CLEAR) -o $(OUT_FILES_STATE_CLEAR)
	@mkdir -p $(BUILD)
	@mv $(OUT_FILES_STATE_CLEAR) $(BUILD)

clean:
	@rm -rf *.o

run: $(FILES_BUILD_RUN)
	@$(CPP)
	@$(CC) $(CFLAGS) $(CFLAGCLOGGER) $(FILES_BUILD_RUN) -o $(OUT_FILES_RUN)
	@$(MEMORY_FLAGS) ./$(OUT_FILES_RUN)
	@rm $(OUT_FILES_RUN)

remove:
	@rm -rf *.out 
	@rm -rf ../build/*.out
