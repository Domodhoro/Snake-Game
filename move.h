#ifndef MOVE_H
#define MOVE_H

static void move() {
    static int i   = 0;
    snake.tail[i]  = snake.head;
    snake.head    += snake.direction;

    if (++i >= snake.length) i = 0;

    if      ((snake.direction ==  1 && snake.head % COLUMNS == 0) || (snake.direction == -1 && (snake.head + 1) % COLUMNS == 0)) snake.head -= COLUMNS * snake.direction;
    else if (snake.head < 0)                 snake.head += (COLUMNS * ROWS);
    else if (snake.head >= (COLUMNS * ROWS)) snake.head -= (COLUMNS * ROWS);
}

#endif
