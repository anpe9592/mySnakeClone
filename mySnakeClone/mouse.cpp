
#include <random>
#include "mouse.h"

int mouseRandPos(int pos) {
    // Seed with a real random value, if available
    std::random_device r;
    
    // Choose a random mean between 40 and pos
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(40, (pos - 20));
    
    return uniform_dist(e1);
}


Mouse::Mouse():
hit(false) {
    newPos();
}

void Mouse::newPos() {
    mPosX = mouseRandPos(640);
    mPosY = mouseRandPos(480);
    
    mCollisionBox.w = MOUSE_WIDTH;
    mCollisionBox.h = MOUSE_HEIGHT;
}

bool Mouse::collisionDetector(SDL_Rect a, SDL_Rect b) {
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

void Mouse::move(int width, int height, SDL_Rect snake) {
    hit = false;
    mCollisionBox.x = mPosX;
    mCollisionBox.y = mPosY;
    
    if (collisionDetector(mCollisionBox, snake)) {
        newPos();
    }
}

void Mouse::render(SDL_Renderer* renderer) {
    // Draw mouse
    SDL_Rect mouse = {mPosX, mPosY, MOUSE_WIDTH, MOUSE_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &mouse);
}

SDL_Rect Mouse::returnRect() {
    SDL_Rect rRect;
    rRect.x = mPosX;
    rRect.y = mPosY;
    rRect.w = MOUSE_WIDTH;
    rRect.h = MOUSE_HEIGHT;
    
    return rRect;
}
