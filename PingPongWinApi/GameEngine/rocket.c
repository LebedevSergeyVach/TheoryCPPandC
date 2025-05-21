#include "rocket.h"

/**
 * Обрабатывает движение ракетки
 *
 * Изменяет позицию ракетки в соответствии с полученной командой.
 * Проверяет границы поля для предотвращения выхода ракетки за пределы.
 *
 * @param rocketNum Номер ракетки (1 или 2)
 * @param rocket Текущая позиция ракетки по вертикали
 * @param command Код нажатой клавиши
 *
 * @return int Новая позиция ракетки
 */
int moveRocket(int rocketNum, int rocket, char command)
{
    if (rocketNum == 1)
    {
        if ((command == PLAYER1_UP || command == tolower(PLAYER1_UP)) && (rocket - 3 > 0))
            rocket--;
        if ((command == PLAYER1_DOWN || command == tolower(PLAYER1_DOWN)) && (rocket + 2 < HEIGHT_FIELD))
            rocket++;
    }
    if (rocketNum == 2)
    {
        if ((command == PLAYER2_UP || command == tolower(PLAYER2_UP)) && (rocket - 3 > 0))
            rocket--;
        if ((command == PLAYER2_DOWN || command == tolower(PLAYER2_DOWN)) && (rocket + 2 < HEIGHT_FIELD))
            rocket++;
    }
    return rocket;
}

/**
 * Проверяет столкновение мяча с ракеткой
 *
 * Определяет, коснулся ли мяч ракетки по вертикальной координате.
 *
 * @param ball Вертикальная позиция мяча
 * @param rocket Вертикальная позиция центра ракетки
 *
 * @return int 1 если было столкновение, иначе 0
 */
int ballHitRocket(int ballY, int rocket_y)
{
    return (ballY == rocket_y - 1 || ballY == rocket_y || ballY == rocket_y + 1);
}
