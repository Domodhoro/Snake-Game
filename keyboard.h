#ifndef KEYBOARD_H
#define KEYBOARD_H

static void set_direction(int direction) {
    if (direction != -1 * snake.direction || snake.length == 0) snake.direction = direction;
}

static void keyboard_callback(bool *quit) {
    switch (sdl.event.key.keysym.sym) {
    case SDLK_ESCAPE:
        *quit = true;
        break;
    case SDLK_w:
        set_direction(-1 * COLUMNS);
        break;
    case SDLK_s:
        set_direction(COLUMNS);
        break;
    case SDLK_a:
        set_direction(-1);
        break;
    case SDLK_d:
        set_direction(1);
        break;
    }
}

#endif
