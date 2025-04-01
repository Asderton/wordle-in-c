#ifndef GRID_H
#define GRID_H

#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<stdlib.h>
#include<string.h>
#include "utilities.h"


//Terminal art for grid
#define BOUNDS ("|---| ")
#define CONTAINER ("|   | ")

//Absolute positions for cursor
#define START_OF_LINE 2
#define CURRENT_POSITION (cursor.y, cursor.x)
#define _CURRENT_POSITION (_cursor -> y, _cursor -> x)
#define START_POSITION 2,1

//Relative positions for cursor
#define NEXT_ROW (cursor.y + 4, 2)
#define DOWN += 4
#define RIGHT += 6
#define LEFT -= 6

//Character manipulation
#define MAKE_UPPER -= 32
#define MAKE_LOWER += 32

//Others
#define ESC 27

//Config
#define LETTER_QUANTITY 5
#define CHANCES 6
#define CELL_SIZE 6



//Movement along the rows
char *get_guess(Position_t *_cursor);
void erase_line(Position_t *_cursor);

//Creation of the rows
void make_grid(void);
void print_container(void);
void print_bound(void);

#endif 