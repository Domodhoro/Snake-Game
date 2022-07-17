#ifndef KEYBOARD_H
#define KEYBOARD_H

static void setDirection(int dir) {
    if (dir != -1 * snake.direction || snake.length == 0) {
        snake.direction = dir;
    }
}

static void keyboardCallback(bool* quit) {
    switch (sdl.event.key.keysym.sym) {
        case SDLK_ESCAPE:
            *quit = true;
            break;
        case SDLK_w:
            setDirection(-1 * COLUMNS);
            break;
        case SDLK_s:
            setDirection(COLUMNS);
            break;
        case SDLK_a:
            setDirection(-1);
            break;
        case SDLK_d:
            setDirection(1);
            break;
    }
}

#endif
