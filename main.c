/*
    MIT License

    Copyright (c) 2023 Guilherme M. Aguiar (guilhermemaguiar2022@gmail.com)

    Permission is hereby granted, free of charge, to any person obtaining a copy
    of this software and associated documentation files (the "Software"), to deal
    in the Software without restriction, including without limitation the rights
    to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
    copies of the Software, and to permit persons to whom the Software is
    furnished to do so, subject to the following conditions:

    The above copyright notice and this permission notice shall be included in all
    copies or substantial portions of the Software.

    THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
    IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
    FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
    AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
    LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
    OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
    SOFTWARE.
*/

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
