#ifndef DRAW_BOARD_H
#define DRAW_BOARD_H

static void drawBoard() {
    for (int i = 0; i < snake.length; ++i) {
        drawBlock(snake.tail[i], 0, 127, 0);
    }

    drawBlock(snake.head, 0, 255, 0);
    drawBlock(applePosition, 255, 0, 0);
}


#endif
