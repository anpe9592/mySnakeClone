
#include "snake.h"

void Snake::render(SDL_Renderer* renderer) {
    // Draw snake
    SDL_Rect snake = {mPosX, mPosY, 20, 20};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &snake);
}
