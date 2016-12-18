
#include "mouse.h"

void Mouse::move(int width, int height) {
    hit = false;
    
    // Check if the snake moved to far left or right
    if ((mPosX < 40) || (mPosX + MOUSE_WIDTH > width)) {
        mPosX = 50;
    }
    
    hit = false;
    
    // Check if the snake moved to far up or down
    if ((mPosY < 40) || (mPosY + MOUSE_HEIGHT > height)) {
        mPosY = 50;
    }
}

void Mouse::render(SDL_Renderer* renderer) {
    // Draw mouse
    SDL_Rect mouse = {mPosX - MOUSE_WIDTH, mPosY - MOUSE_HEIGHT, MOUSE_WIDTH, MOUSE_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &mouse);
}
