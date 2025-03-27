#ifndef WORDLE_H
#define WORDLE_H

#include<stdio.h>
#include<ncurses.h>
#include "validate.h"
#include "grid.h"
#include "menu.h"

typedef struct game_state{
    int n_letters;
    int chances;
    int language;
    bool won;
} game_state;


void end_game(bool won, int attempts, enum Color **attempt_color_code, char *answer);



#endif