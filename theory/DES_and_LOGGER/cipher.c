#include <ctype.h>
#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef LOGGER
#include "logger.h"
#endif

#define MAX_FILE 100
#define MAX_BUFFER 2000
#define MAX_BUFFER_DEC 5000

int read_file(char *file, char *str, int *file_availability);
int append_file(char *file, char *str, int file_availability);
int source_encryption();
int source_encryption_dec(int operation_mode);
int encrypting_files_in_directory(const char *directory);
int encrypting_files_in_directory_dec(const char *directory);
int decrypting_files_in_directory_dec(const char *directory);
void caesar_cipher(char *text, int shift);
void print_error_na(int programm);

int main()
{
    printf("1 - Read file\n2 - Append file\n3 - Caesar encryption\n4 - DES encryption\n5 - Decryption of DES\n-1 - Exit\n");

    int programm = 0;
    int operation_mode;

    char *file = malloc(MAX_FILE * sizeof(char));
    char *str = malloc(MAX_FILE * sizeof(char));

    int file_availability = 1;

    while (scanf("%d", &operation_mode) || getchar() != '\n')
    {
        if (operation_mode == 1)
        {
            scanf("%100s", str);
            programm = read_file(file, str, &file_availability);
        }
        else if (operation_mode == 2)
        {
            programm = append_file(file, str, file_availability);
        }
        else if (operation_mode == 3)
        {
            programm = source_encryption();
        }
        else if (operation_mode == 4)
        {
            programm = source_encryption_dec(operation_mode);
        }
        else if (operation_mode == 5)
        {
            programm = source_encryption_dec(operation_mode);
        }
        else if (operation_mode == -1)
        {
            break;
        }
        else
        {
            programm = -1;
        }

        print_error_na(programm);
    }

    print_error_na(programm);

    free(file);
    free(str);

    return programm;
}

int read_file(char *file, char *str, int *file_availability)
{
    int programm = 0;

#ifdef LOGGER
    FILE *log_file = log_init("cipher.log");
    if (log_file == NULL)
    {
        logcat(log_file, "READ FILE: ERROR LOG", ERROR);
        programm = 1;
    }
#endif

    strcpy(file, str);

    FILE *file_read = fopen(file, "r");

    if (file_read == NULL)
    {
        programm = 1;
        *file_availability = 1;

#ifdef LOGGER
        logcat(log_file, "READ FILE: File not found", ERROR);
#endif
    }
    else
    {
        *file_availability = 0;
        char ch;

        while ((ch = fgetc(file_read)) != EOF)
        {
            putchar(ch);
        }
        printf("\n");

        fclose(file_read);

#ifdef LOGGER
        logcat(log_file, "READ FILE: Read successfully", INFO);
#endif
    }

#ifdef LOGGER
    log_close(log_file);
#endif

    return programm;
}

int append_file(char *file, char *str, int file_availability)
{
    int programm = 0;

#ifdef LOGGER
    FILE *log_file = log_init("cipher.log");
    if (log_file == NULL)
    {
        logcat(log_file, "APPEND FILE: ERROR LOG", ERROR);
        programm = 1;
    }
#endif
    FILE *file_append = fopen(file, "a+");

    if (file_append == NULL)
    {
        programm = 1;

#ifdef LOGGER
        logcat(log_file, "APPEND FILE: Failed to open file for appending (a+)", ERROR);
#endif
    }
    else if (file_availability != 0)
    {
        fclose(file_append);
        programm = 1;

#ifdef LOGGER
        logcat(log_file, "APPEND FILE: File not found", ERROR);
#endif
    }
    else
    {
        getchar();

        char ch;
        while (scanf("%c", &ch))
        {
            if (ch != '\n')
            {
                fputc(ch, file_append);
            }
            else
            {
                break;
            }
        }

        fclose(file_append);

        read_file(file, str, &file_availability);

#ifdef LOGGER
        logcat(log_file, "APPEND FILE: Append successfully", INFO);
#endif
    }

#ifdef LOGGER
    log_close(log_file);
#endif

    return programm;
}

int source_encryption()
{
    int programm = 0;

    char *directory = malloc(MAX_FILE * sizeof(char));

    scanf("%99s", directory);

    programm = encrypting_files_in_directory(directory);

    free(directory);
    return programm;
}

int source_encryption_dec(int operation_mode)
{
    int programm = 0;

    char *directory = malloc(MAX_FILE * sizeof(char));

    scanf("%99s", directory);

    if (operation_mode == 4)
    {

        programm = encrypting_files_in_directory_dec(directory);
    }
    else if (operation_mode == 5)
    {
        programm = decrypting_files_in_directory_dec(directory);
    }
    else
    {
        programm = 1;
    }

    free(directory);
    return programm;
}

int encrypting_files_in_directory(const char *directory)
{
    int programm = 0;

#ifdef LOGGER
    FILE *log_file = log_init("cipher.log");
    if (log_file == NULL)
    {
        logcat(log_file, "ENCRYPTING FILES IN DIRECTORY: ERROR LOG", ERROR);
        programm = 1;
    }
#endif

    DIR *dir = opendir(directory);

    if (dir == NULL)
    {
        programm = 1;

#ifdef LOGGER
        logcat(log_file, "ENCRYPTING FILES IN DIRECTORY: Failed to open directory", ERROR);
#endif
    }
    else
    {
        int shift_for_caesar;

        if (scanf("%d", &shift_for_caesar) != 1 || getchar() != '\n')
        {
            programm = 1;

#ifdef LOGGER
            logcat(log_file, "ENCRYPTING FILES IN DIRECTORY: Invalid shift value", ERROR);
#endif
        }
        else
        {
            struct dirent *ent;

            while ((ent = readdir(dir)) != NULL)
            {
                if (ent->d_name[0] == '.')
                    continue;

                char file_path[MAX_BUFFER];
                snprintf(file_path, MAX_BUFFER, "%s/%s", directory, ent->d_name);

                if (strstr(ent->d_name, ".c") != NULL)
                {
                    FILE *file = fopen(file_path, "r+");
                    if (file == NULL)
                    {
                        programm = 1;
#ifdef LOGGER
                        logcat(log_file, "ENCRYPTING FILES IN DIRECTORY: Failed to open .c file", ERROR);
#endif
                    }
                    else
                    {
                        fseek(file, 0, SEEK_END);
                        long file_size = ftell(file);
                        fseek(file, 0, SEEK_SET);

                        char *buffer = malloc(file_size + 1);
                        fread(buffer, 1, file_size, file);
                        buffer[file_size] = '\0';

                        caesar_cipher(buffer, shift_for_caesar);

                        fseek(file, 0, SEEK_SET);
                        fwrite(buffer, 1, file_size, file);
                        fclose(file);

                        free(buffer);

#ifdef LOGGER
                        logcat(log_file, "ENCRYPTING FILES IN DIRECTORY: Encrypted .c file", INFO);
#endif
                    }
                }
                else if (strstr(ent->d_name, ".h") != NULL)
                {
                    FILE *file = fopen(file_path, "w");
                    if (file == NULL)
                    {
                        programm = 1;

#ifdef LOGGER
                        logcat(log_file, "ENCRYPTING FILES IN DIRECTORY: Failed to open .h file", ERROR);
#endif
                    }
                    else
                    {
                        fclose(file);

#ifdef LOGGER
                        logcat(log_file, "ENCRYPTING FILES IN DIRECTORY: Cleared .h file", INFO);
#endif
                    }
                }
            }

            closedir(dir);
        }
    }

#ifdef LOGGER
    log_close(log_file);
#endif

    return programm;
}

int encrypting_files_in_directory_dec(const char *directory)
{
    int programm = 0;

#ifdef LOGGER
    FILE *log_file = log_init("cipher.log");
    if (log_file == NULL)
    {
        logcat(log_file, "ENCRYPTING FILES IN DIRECTORY DEC: ERROR LOG", ERROR);
        programm = 1;
    }
#endif

    DIR *dir = opendir(directory);

    if (dir == NULL)
    {
        programm = 1;

#ifdef LOGGER
        logcat(log_file, "ENCRYPTING FILES IN DIRECTORY DEC: Failed to open directory", ERROR);
#endif
    }
    else
    {
        struct dirent *ent;

        while ((ent = readdir(dir)) != NULL)
        {
            if (ent->d_name[0] == '.')
                continue;
            char file_path[MAX_BUFFER];
            snprintf(file_path, MAX_BUFFER - 500, "%s/%s", directory, ent->d_name);
            if (strstr(ent->d_name, ".c") != NULL)
            {
                char command[MAX_BUFFER_DEC];
                char *ssl1 = "openssl des-cbc -in ";
                char *ssl2 = " -out ";
                snprintf(command, MAX_BUFFER_DEC, "%s%s%s%s", ssl1, file_path, ssl2, file_path);
                system(command);

#ifdef LOGGER
                logcat(log_file, "ENCRYPTING FILES IN DIRECTORY DEC: Encrypted DEC .c file", INFO);
#endif
            }
            else if (strstr(ent->d_name, ".h") != NULL)
            {
                FILE *file = fopen(file_path, "w");
                if (file == NULL)
                {
                    programm = 1;

#ifdef LOGGER
                    logcat(log_file, "ENCRYPTING FILES IN DIRECTORY DEC: Failed to open .h file", ERROR);
#endif
                }
                else
                {
                    fclose(file);

#ifdef LOGGER
                    logcat(log_file, "ENCRYPTING FILES IN DIRECTORY DEC: Cleared .h file", INFO);
#endif
                }
            }
        }

        closedir(dir);
    }

#ifdef LOGGER
    log_close(log_file);
#endif

    return programm;
}

int decrypting_files_in_directory_dec(const char *directory)
{
    int programm = 0;

#ifdef LOGGER
    FILE *log_file = log_init("cipher.log");
    if (log_file == NULL)
    {
        logcat(log_file, "DECRYPTING FILES IN DIRECTORY DEC: ERROR LOG", ERROR);
        programm = 1;
    }
#endif

    DIR *dir = opendir(directory);

    if (dir == NULL)
    {
        programm = 1;

#ifdef LOGGER
        logcat(log_file, "DECRYPTING FILES IN DIRECTORY DEC: Failed to open directory", ERROR);
#endif
    }
    else
    {
        struct dirent *ent;

        while ((ent = readdir(dir)) != NULL)
        {
            if (ent->d_name[0] == '.')
                continue;
            char file_path[MAX_BUFFER];
            snprintf(file_path, MAX_BUFFER - 500, "%s/%s", directory, ent->d_name);
            if (strstr(ent->d_name, ".c") != NULL)
            {
                char command[MAX_BUFFER_DEC];
                char *ssl1 = "openssl des-cbc -d -in ";
                char *ssl2 = " -out ";
                snprintf(command, MAX_BUFFER_DEC, "%s%s%s%s", ssl1, file_path, ssl2, file_path);
                system(command);

#ifdef LOGGER
                logcat(log_file, "DECRYPTING FILES IN DIRECTORY DEC: Decrypted .c file", INFO);
#endif
            }
        }

        closedir(dir);
    }

#ifdef LOGGER
    log_close(log_file);
#endif

    return programm;
}

void caesar_cipher(char *text, int shift)
{
    for (int i = 0; text[i] != '\0'; i++)
    {
        if (isalpha(text[i]))
        {
            char base = islower(text[i]) ? 'a' : 'A';
            text[i] = (text[i] - base + shift) % 26 + base;
        }
    }
}

void print_error_na(int programm)
{
    if (programm != 0)
        printf("n/a\n");
}
