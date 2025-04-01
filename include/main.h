#ifndef WORDLE_H
#define WORDLE_H

#include "validate.h"
#include "grid.h"
#include "menu.h"
#include "utilities.h"




void end_game(game_settings *game, int attempts, enum Color **attempt_color_code, char *answer);



#endif