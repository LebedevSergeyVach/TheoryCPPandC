CC = gcc
CFLAGS = -Wall -Wextra -Werror

BUILD = ../build
OUTFILES_Q1 = Quest_1
OUTFILES_Q2 = Quest_2
OUTFILES_Q3 = Quest_3

FILESBUILD_DOORS = dmanager_module.c
FILESBUILD_LINKED_LIST = list.c list_test.c

.PHONY: all clean door_struct

all: door_struct list_test clean

door_struct: $(FILESBUILD_DOORS)
	@$(CC) $(CFLAGS) $(FILESBUILD_DOORS) -o $(OUTFILES_Q1)
	@mkdir -p $(BUILD)
	@mv $(OUTFILES_Q1) $(BUILD)

list_test: $(FILESBUILD_LINKED_LIST)
	@$(CC) $(CFLAGS) $(FILESBUILD_LINKED_LIST) -o $(OUTFILES_Q2)
	@mkdir -p $(BUILD)
	@mv $(OUTFILES_Q2) $(BUILD)

clean:
	@rm -rf *.o *.a *.so *.out
