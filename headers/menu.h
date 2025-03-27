#ifndef MENU_H
#define MENU_H

#include<stdio.h>
#include<stdlib.h>
#include<ncurses.h>
#include "../headers/grid.h"
#include "../headers/validate.h"
#include "../headers/wordle.h"

#define DEFAULT_LANGUAGE "en"

char *start_menu(char *language);
char *language_menu(char *language);

#endif