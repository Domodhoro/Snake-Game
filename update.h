#ifndef UPDATE_H
#define UPDATE_H

static uint32_t ticks   = 0;
static uint32_t count   = 0;
static uint32_t current = 0;
static uint32_t delta   = 0;

static void update() {
    current  = SDL_GetTicks();
    delta    = current - ticks;
    ticks    = current;
    count   += delta;

    if (count >= SPEED && !snake.dead) {
        count = 0;
        move();

        if (snake.head == apple_position) {
            set_apple_position();

            snake.tail[snake.length++] = snake.head;
        } else if (collision_with_tail(snake.head)) snake.dead = true;
    }

    draw_board();
}

#endif
