#ifndef DRAW_BLOCK_H
#define DRAW_BLOCK_H

static void drawBlock(int position, int r, int g, int b) {
    SDL_Rect rect = {
        position % COLUMNS, position / COLUMNS, BLOCK_SIZE, BLOCK_SIZE
    };

    rect.x *= BLOCK_SIZE;
    rect.y *= BLOCK_SIZE;

    SDL_SetRenderDrawColor(sdl.renderer, r, g, b, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(sdl.renderer, &rect);
}

#endif
