#ifndef INIT_H
#define INIT_H

#include <SDL.h>
#include <SDL_image.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int init(SDL_Window** window, SDL_Renderer** renderer);
SDL_Texture* load_texture(const char* path, SDL_Renderer* renderer);

#endif
