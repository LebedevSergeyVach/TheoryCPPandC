#ifndef RENDER_SCREEN_GAME_H
#define RENDER_SCREEN_GAME_H

#include "renderGame.h"

/**
 * Отрисовывает игровое поле
 *
 * Формирует в буфере изображение игрового поля с ракетками, мячом и границами.
 * Выводит текущий счет и инструкции по управлению.
 *
 * @param centerRocketOne Позиция левой ракетки
 * @param centerRocketTwo Позиция правой ракетки
 * @param ballX Горизонтальная позиция мяча
 * @param ballY Вертикальная позиция мяча
 * @param scorePlayerOne Счет первого игрока
 * @param scorePlayerTwo Счет второго игрока
 *
 * @see printTable
 */
void printGameField(int centerRocketOne, int centerRocketTwo, int ballX, int ballY,
                    int scorePlayerOne, int scorePlayerTwo);

/**
 * Отрисовывает таблицу счета
 *
 * Выводит в верхней части экрана текущий счет игроков.
 *
 * @param scorePlayerOne Счет первого игрока
 * @param scorePlayerTwo Счет второго игрока
 */
void printTable(int scorePlayerOne, int scorePlayerTwo);

/**
 * Показывает экран победы
 *
 * Отображает сообщение о победителе и итоговый счет.
 * Ожидает нажатия любой клавиши для возврата в меню.
 *
 * @param scorePlayerOne Счет первого игрока
 * @param scorePlayerTwo Счет второго игрока
 */
void printWinPlayer(int scorePlayerOne, int scorePlayerTwo);

#endif
