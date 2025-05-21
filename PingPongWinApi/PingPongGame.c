#include "LibrariesAndDefine/connection.h"
#include "RenderingTheGame/renderGame.h"
#include "GameEngine/game.h"

/**
 * Комплияция и запуск: gcc PingPongGame.c RenderingTheGame/*.c GameEngine/*.c -o PingPongGame.exe && clear && ./PingPongGame.exe
 * Необходимо подождать загрузки и компиляции Win API
 */
int main()
{
    initConsole();

    while (true)
    {
        GameSettings settings = showMenu();
        runGame(settings);
    }

    return 0;
}
