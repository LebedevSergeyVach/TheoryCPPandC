#ifndef BOUNCE_WALL_H
#define BOUNCE_WALL_H

#include "game.h"

/**
 * Обрабатывает отскок мяча от стен
 * 
 * Меняет направление мяча при столкновении с верхней или нижней стенкой.
 * 
 * @param direction Текущее направление мяча по вертикали
 * @param ball Вертикальная позиция мяча
 * 
 * @return int Новое направление мяча по вертикали
 */
int bounceWall(int direction, int ball);

#endif
