#ifndef APPLE_H
#define APPLE_H

int apple_position = floor((COLUMNS * ROWS) / 3);

static bool collision_with_tail(int position) {
    for (int i = 0; i < snake.length; ++i) if (snake.tail[i] == position) return true;

    return false;
}

static void set_apple_position() {
    do     apple_position = rand() % (COLUMNS * ROWS);
    while (snake.head == apple_position || collision_with_tail(apple_position));
}

#endif
