#ifndef UPDATE_H
#define UPDATE_H

static uint32_t ticks = 0, count = 0, current = 0, delta = 0;

static void update() {
    current = SDL_GetTicks();
    delta = current - ticks;
    ticks = current;

    count += delta;

    if (count >= SPEED && !snake.dead) {
        count = 0;

        move();

        if (snake.head == applePosition) {
            setApplePosition();

            snake.tail[snake.length++] = snake.head;
        } else if (collisionWithTail(snake.head)) {
            snake.dead = true;
        }
    }

    drawBoard();
}

#endif
