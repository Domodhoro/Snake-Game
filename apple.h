#ifndef APPLE_H
#define APPLE_H

int applePosition = floor((COLUMNS * ROWS) / 3);

static bool collisionWithTail(int position) {
    for (int i = 0; i < snake.length; ++i) {
        if (snake.tail[i] == position) {
            return true;
        }
    }

    return false;
}

static void setApplePosition() {
    do {
        applePosition = rand() % (COLUMNS * ROWS);
    } while (snake.head == applePosition || collisionWithTail(applePosition));
}

#endif
