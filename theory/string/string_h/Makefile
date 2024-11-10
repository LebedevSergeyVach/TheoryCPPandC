CC=gcc
CFLAGS = -Wall -Wextra -Werror

BUILD = ../build
OUTFILES_Q1 = Quest_1
OUTFILES_Q2 = Quest_2
OUTFILES_Q3 = Quest_3
OUTFILES_Q4 = Quest_4
OUTFILES_Q5 = Quest_5

FILESBILD_S21_STRING_TEST = s21_string_test.c s21_string.c

.PHONY: all clean strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests

all: strlen_tests strcmp_tests strcpy_tests strcat_tests strchr_tests clean

strlen_tests: $(FILESBILD_S21_STRING_TEST)
	@$(CC) $(CFLAGS) -DTEST_STRLEN $(FILESBILD_S21_STRING_TEST) -o $(OUTFILES_Q1)
	@mkdir -p $(BUILD)
	@mv $(OUTFILES_Q1) $(BUILD)

strcmp_tests: $(FILESBILD_S21_STRING_TEST)
	@$(CC) $(CFLAGS) -DTEST_STRCMP $(FILESBILD_S21_STRING_TEST) -o $(OUTFILES_Q2)
	@mkdir -p $(BUILD)
	@mv $(OUTFILES_Q2) $(BUILD)

strcpy_tests:
	@$(CC) $(CFLAGS) -DTEST_STRCPY $(FILESBILD_S21_STRING_TEST) -o $(OUTFILES_Q3)
	@mkdir -p $(BUILD)
	@mv $(OUTFILES_Q3) $(BUILD)

strcat_tests: $(FILESBILD_S21_STRING_TEST)
	@$(CC) $(CFLAGS) -DTEST_STRCAT $(FILESBILD_S21_STRING_TEST) -o $(OUTFILES_Q4)
	@mkdir -p $(BUILD)
	@mv $(OUTFILES_Q4) $(BUILD)

strchr_tests: $(FILESBILD_S21_STRING_TEST)
	@$(CC) $(CFLAGS) -DTEST_STRCHR $(FILESBILD_S21_STRING_TEST) -o $(OUTFILES_Q5)
	@mkdir -p $(BUILD)
	@mv $(OUTFILES_Q5) $(BUILD)

clean:
	@rm -rf *.o *.a *.so *.out
