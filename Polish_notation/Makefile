CC=gcc
CFLAGS = -Wall -Wextra -Werror

BUILD = ../build
OUTFILES = graph

FILESBILD = graph.o operation.o postfix.o stack.o

.PHONY: all build clean

all: build

rebuild: clean all

build: $(FILESBILD)
	@$(CC) $(CFLAGS) $(FILESBILD) -o $(OUTFILES)
	@mkdir -p $(BUILD)
	@mv $(OUTFILES) $(BUILD)

run: $(FILESBILD)
	@$(CC) $(CFLAGS) $(FILESBILD) -o $(OUTFILES)
	@./$(OUTFILES)
	@rm $(OUTFILES)
	@rm -rf *.o

graph.o:
	@$(CC) $(CFLAGS) -c graph.c

operation.o:
	@$(CC) $(CFLAGS) -c operation.c

postfix.o:
	@$(CC) $(CFLAGS) -c postfix.c

stack.o:
	@$(CC) $(CFLAGS) -c stack.c

clean:
	@rm -rf *.o
