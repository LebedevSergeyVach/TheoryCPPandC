#ifndef CONNECTION_H
#define CONNECTION_H

#include "include.h"
#include "define.h"

HANDLE hConsoleOutput;
COORD cursorPosition;
CHAR_INFO consoleBuffer[CONSOLE_HEIGHT][CONSOLE_WIDTH];

// Структура для настроек игры
typedef struct
{
    int timeLag;
    int winScore;
} GameSettings;

#endif
