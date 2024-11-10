CC=gcc
CFLAGS = -Wall -Wextra -Werror

BUILD = ../../build
OUTFILES_Q3 = Quest_3.out
OUTFILES_Q5 = Quest_5.out
OUTFILES_Q6 = Quest_6.out

FILESBILD = data_process.o data_stat.o data_io.o decision.o main_executable_module.o

.PHONY: all build data_stat.a build_with_static clean

all: build

build_static: build_with_static

rebuild: clean all

rebuild_static: clean build_with_static

build: $(FILESBILD)
	@$(CC) $(CFLAGS) $(FILESBILD) -o $(OUTFILES_Q3)
	@mkdir -p $(BUILD)
	@mv $(OUTFILES_Q3) $(BUILD)

main_executable_module.o:
	@$(CC) $(CFLAGS) -c main_executable_module.c

data_process.o:
	@$(CC) $(CFLAGS) -c ../data_module/data_process.c

data_stat.o:
	@$(CC) $(CFLAGS) -c ../data_libs/data_stat.c

data_io.o:
	@$(CC) $(CFLAGS) -c ../data_libs/data_io.c

decision.o:
	@$(CC) $(CFLAGS) -c ../yet_another_decision_module/decision.c

data_stat.a: data_stat.o
	@ar rcs libdata_stat.a data_stat.o

build_with_static: data_stat.a $(filter-out data_stat.o, $(FILESBILD))
	@$(CC) $(CFLAGS) $(filter-out data_stat.o, $(FILESBILD)) -L. -ldata_stat -o $(OUTFILES_Q5)
	@mkdir -p $(BUILD)
	@mv $(OUTFILES_Q5) $(BUILD)

clean:
	@rm -rf *.o *.a *.so

