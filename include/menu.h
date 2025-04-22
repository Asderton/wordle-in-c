#ifndef MENU_H
#define MENU_H

#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include "utilities.h"





void start_menu(game_settings *game);
void language_menu(game_settings *game);
void difficulty_menu(game_settings *game);
void end_game(game_settings *game, int attempts, enum Color **attempt_color_code, char *answer);

#endif
