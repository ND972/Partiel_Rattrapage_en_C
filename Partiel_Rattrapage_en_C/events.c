#include "events.h"
#include <SDL.h>

int handle_events(int* rect_x, int* rect_y, int* running, int* dirX, int* dirY) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_QUIT:
            *running = 0;
            break;
        case SDL_KEYDOWN:
            switch (event.key.keysym.sym) {
            case SDLK_UP:
                *dirX = 0;
                *dirY = -2;
                break;
            case SDLK_DOWN:
                *dirX = 0;
                *dirY = 2;
                break;
            case SDLK_LEFT:
                *dirX = -2;
                *dirY = 0;
                break;
            case SDLK_RIGHT:
                *dirX = 2;
                *dirY = 0;
                break;
            }
            break;
        }
    }
    return 1;
}
