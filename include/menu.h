#ifndef MENU_H
#define MENU_H

#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include "utilities.h"






void start_menu(game_settings *game);
void language_menu(game_settings *game);
void difficulty_menu(game_settings *game);

#endif
