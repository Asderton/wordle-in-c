#ifndef WORDLE_H
#define WORDLE_H

#include "validate.h"
#include "grid.h"
#include<stdio.h>
#include<ncurses.h>



void end_game(bool won, int attempts, enum Color **attempt_color_code);



#endif