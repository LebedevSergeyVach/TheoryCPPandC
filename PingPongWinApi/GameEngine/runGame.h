#ifndef RUN_GAME_H
#define RUN_GAME_H

#include "game.h"

/**
 * Основной игровой цикл
 *
 * Управляет процессом игры: обработкой ввода, обновлением состояния, отрисовкой.
 * Содержит логику движения мяча, подсчета очков и определения победителя.
 *
 * @param settings Настройки игры (скорость, лимит очков)
 *
 * @see printGameField, moveRocket, ballHitRocket, bounceWall
 */
void runGame(GameSettings settings);

#endif
