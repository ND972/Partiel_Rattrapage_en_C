#include <SDL.h>
#include <stdio.h>
#include "init.h"
#include "events.h"
#include "render.h"
#include "cleanup.h"

// Dimensions de la fenetre
#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Texture* background = NULL;
    int rect_x = SCREEN_WIDTH / 2;
    int rect_y = SCREEN_HEIGHT / 2;
    int dirX = 0;
    int dirY = 0;
    int running = 1;

    if (!init(&window, &renderer)) {
        return 1;
    }

    // Load background texture
    background = load_texture("cat.jpeg", renderer);
    if (background == NULL) {
        printf("Failed to load background texture!\n");
        cleanup(window, renderer);
        return 1;
    }

    while (running) {
        handle_events(&rect_x, &rect_y, &running, &dirX, &dirY);

        // Update rectangle position
        rect_x += dirX;
        rect_y += dirY;

        render(renderer, background, rect_x, rect_y);
    }

    SDL_DestroyTexture(background);
    cleanup(window, renderer);

    return 0;
}
