#ifndef DRAW_BOARD_H
#define DRAW_BOARD_H

static void draw_board() {
    for (int i = 0; i < snake.length; ++i) draw_block(snake.tail[i], 0, 127, 0);

    draw_block(snake.head, 0, 255, 0);
    draw_block(apple_position, 255, 0, 0);
}


#endif
