#ifndef UTIL_H
#define UTIL_H

enum {
    SPEED      = 200,
    BLOCK_SIZE = 20,
    COLUMNS    = 40,
    ROWS       = 20
};

struct {
    SDL_Renderer* renderer;
    SDL_Window* window;
    SDL_Event event;
} sdl = {NULL, NULL};

struct {
    int head;
    int direction;
    int length;
    int tail[COLUMNS * ROWS];

    bool dead;
} snake = {
    0, 1, 4, {0}, false
};

#endif
