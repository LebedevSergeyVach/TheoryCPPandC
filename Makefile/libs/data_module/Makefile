CC=gcc
CFLAGS = -Wall -Wextra -Werror

BUILD = ../../build
OUTFILES = Quest_3.out
FILESBILD = data_module_entry.o data_process.o data_io.o data_stat.o

.PHONY: all build clean

all: build clean


build: $(FILESBILD)
	@$(CC) $(CFLAGS) $(FILESBILD) -o $(OUTFILES)
	@mkdir -p $(BUILD)
	@mv $(OUTFILES) $(BUILD)

data_module_entry.o:
	@$(CC) $(CFLAGS) -c data_module_entry.c

data_process.o:
	@$(CC) $(CFLAGS) -c data_process.c

data_io.o:
	@$(CC) $(CFLAGS) -c ../data_libs/data_io.c

data_stat.o:
	@$(CC) $(CFLAGS) -c ../data_libs/data_stat.c

clean:
	@rm -rf *.o
	