#include "render.h"
#include <SDL.h>

void render(SDL_Renderer* renderer, SDL_Texture* background, int rect_x, int rect_y) {
    // Clear the screen
    SDL_RenderClear(renderer);

    // Render the background texture
    SDL_RenderCopy(renderer, background, NULL, NULL);

    // Set the draw color to red for the rectangle
    SDL_Rect fillRect = { rect_x, rect_y, 50, 50 };
    SDL_SetRenderDrawColor(renderer, 0xFF, 0x00, 0x00, 0xFF);
    SDL_RenderFillRect(renderer, &fillRect);

    // Update the screen
    SDL_RenderPresent(renderer);
}
