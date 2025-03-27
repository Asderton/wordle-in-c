#ifndef MENU_H
#define MENU_H

#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include "grid.h"
#include "validate.h"
#include "wordle.h"

#define EN 0
#define ES 1

typedef struct game_state{
    int n_letters;
    int chances;
    int language;
    bool won;
} game_state;

void start_menu(game_state *game);
void language_menu(game_state *game);
void difficulty_menu(game_state *game);

#endif
