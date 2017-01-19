
#include <random>
#include "mouse.h"

int mouseRandPos(int pos) {
    // Seed with a real random value, if available
    std::random_device r;
    
    // Choose a random mean between 40 and pos
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(40, pos);
    
    return uniform_dist(e1);
}

void Mouse::move(int width, int height) {
    hit = false;
    
    mPosX = mouseRandPos(width);
    mPosY = mouseRandPos(height);
}

void Mouse::render(SDL_Renderer* renderer) {
    // Draw mouse
    SDL_Rect mouse = {mPosX - MOUSE_WIDTH, mPosY - MOUSE_HEIGHT, MOUSE_WIDTH, MOUSE_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &mouse);
}
