
#include <random>
#include "mouse.h"

bool collisionDetector(SDL_Rect a, SDL_Rect b) {
    int leftA,   leftB;
    int rightA,  rightB;
    int topA,    topB;
    int bottomA, bottomB;
    
    leftA   = a.x;
    rightA  = a.x + a.w;
    topA    = a.y;
    bottomA = a.y + a.h;
    
    leftB   = b.x;
    rightB  = b.x + b.w;
    topB    = b.y;
    bottomB = b.y + b.h;
    
    if (bottomA <= topB) {
        return false;
    }
    
    if (topA >= bottomB) {
        return false;
    }
    
    if (rightA <= leftB) {
        return false;
    }
    
    if (leftA >= rightB) {
        return false;
    }
    
    return true;
}

int mouseRandPos(int pos) {
    // Seed with a real random value, if available
    std::random_device r;
    
    // Choose a random mean between 40 and pos
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(40, pos);
    
    return uniform_dist(e1);
}


Mouse::Mouse():
mPosX(50), mPosY(50), hit(false) {
    mCollisionBox.w = MOUSE_WIDTH;
    mCollisionBox.h = MOUSE_HEIGHT;
}

void Mouse::move(int width, int height, SDL_Rect snake) {
    hit = false;
    
    if (collisionDetector(mCollisionBox, snake)) {
        mPosX = mouseRandPos(width);
        mPosY = mouseRandPos(height);
    }
}

void Mouse::render(SDL_Renderer* renderer) {
    // Draw mouse
    SDL_Rect mouse = {mPosX - MOUSE_WIDTH, mPosY - MOUSE_HEIGHT, MOUSE_WIDTH, MOUSE_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &mouse);
}
