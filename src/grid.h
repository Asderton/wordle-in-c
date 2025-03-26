#ifndef GRID_H
#define GRID_H
#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include<stdlib.h>
#include<string.h>

#define BOUNDS ("|---| ")
#define CONTAINER ("|   | ")


#define _CURRENT_POSITION (_cursor -> y, _cursor -> x)
#define START_POSITION 2,1

#define NEXT_ROW (cursor.y + 4, 2)


#define RIGHT += 6
#define LEFT -= 6


#define LETTER_QUANTITY 5
#define CHANCES 6
#define CELL_SIZE 6

typedef struct {
    int x;
    int y;
}Position_t;


void make_grid(void);
void print_container(void);
void print_bound(void);
char *get_guess(Position_t *_cursor);
void erase_line(Position_t *_cursor);

#endif 