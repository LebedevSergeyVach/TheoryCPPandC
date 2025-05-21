#include "bounceWall.h"

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
int bounceWall(int direction, int ball) {
    if (direction < 0 && ball == 2) return 1;
    if (direction > 0 && ball == HEIGHT_FIELD - 1) return -1;
    return direction;
}
