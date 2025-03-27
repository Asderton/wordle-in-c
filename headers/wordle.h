#ifndef WORDLE_H
#define WORDLE_H

#include<stdio.h>
#include<ncurses.h>
#include "validate.h"
#include "grid.h"
#include "menu.h"




void end_game(bool won, int attempts, enum Color **attempt_color_code, char *answer);



#endif