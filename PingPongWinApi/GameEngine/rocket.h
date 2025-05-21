#ifndef ROCKET_H
#define ROCKET_H

#include "game.h"

/**
 * Обрабатывает движение ракетки
 *
 * Изменяет позицию ракетки в соответствии с полученной командой.
 * Проверяет границы поля для предотвращения выхода ракетки за пределы.
 *
 * @param rocket_num Номер ракетки (1 или 2)
 * @param rocket Текущая позиция ракетки по вертикали
 * @param command Код нажатой клавиши
 *
 * @return int Новая позиция ракетки
 */
int moveRocket(int rocket_num, int rocket, char command);

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
int ballHitRocket(int ballY, int rocket_y);

#endif
