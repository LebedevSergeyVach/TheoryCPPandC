#ifndef SHOW_MENU_H
#define SHOW_MENU_H

#include "game.h"

/**
 * Отображает главное меню игры
 *
 * Показывает интерактивное меню с настройками скорости игры и очков для победы.
 * Обрабатывает пользовательский ввод для навигации по меню.
 *
 * @return GameSettings Структура с выбранными настройками игры
 *
 * @property selectedSpeed Текущая выбранная скорость (1-3)
 * @property selectedWinScore Текущий выбранный лимит очков (1-3)
 * @property currentSelection Текущий выбранный пункт меню
 */
GameSettings showMenu();

#endif
