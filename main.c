#include <stdio.h>
#include <math.h>
#include <stdbool.h>

#include <SDL2/SDL.h>

const char *TITLE = "SNAKE GAME";

#include "./util.h"
#include "./keyboard.h"
#include "./move.h"
#include "./apple.h"
#include "./draw_block.h"
#include "./draw_board.h"
#include "./update.h"

int main(int argc, const char *argv[]) {
    printf("%s\n", argv[0]);

    srand((int)time(0));

    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("%s", SDL_GetError());
        exit(EXIT_FAILURE);
    }

    SDL_CreateWindowAndRenderer(BLOCK_SIZE * COLUMNS, BLOCK_SIZE * ROWS, 0, &sdl.window, &sdl.renderer);
    SDL_SetWindowTitle         (sdl.window, TITLE);

    bool quit = false;

    while (!quit) {
        if (snake.dead) quit = true;

        while(SDL_PollEvent(&sdl.event)) {
            if(sdl.event.type == SDL_QUIT) quit = true;

            keyboard_callback(&quit);
        }

        SDL_SetRenderDrawColor(sdl.renderer, 0, 0, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderClear       (sdl.renderer);

        update();

        SDL_RenderPresent(sdl.renderer);
    }

    SDL_DestroyRenderer(sdl.renderer);
    SDL_DestroyWindow  (sdl.window);
    SDL_Quit           ();

    return 0;
}
