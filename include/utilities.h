#ifndef TYPES_H
#define TYPES_H

enum Color {RED, YELLOW, GREEN};
#define CURRENT_POSITION (cursor.y, cursor.x)



typedef struct {
    int x;
    int y;
}Position_t;

typedef struct game_settings {
    int n_letters;
    int chances;
    int language;
    bool won;
} game_settings;

#define LETTER_QUANTITY 5
#define EN 0
#define ES 1

#endif