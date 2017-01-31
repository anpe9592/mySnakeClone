
#include "snake.h"

void Snake::setPos(int x, int y) {
    mPosX = x;
    mPosY = y;
    mConstX = x;
    mConstY = y;
}

void Snake::start() {
    mPosX = mConstX;
    mPosY = mConstY;
    mVelX = SNAKE_VEL;
    mVelY = 0;
    hit = false;
}

void Snake::handleEvent(SDL_Event& event) {
    if (!hit) {
        // Key pressed down
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    mVelX = 0;
                    mVelY = -SNAKE_VEL;
                    break;
                case SDLK_DOWN:
                    mVelX = 0;
                    mVelY = +SNAKE_VEL;
                    break;
                case SDLK_LEFT:
                    mVelY = 0;
                    mVelX = -SNAKE_VEL;
                    break;
                case SDLK_RIGHT:
                    mVelY = 0;
                    mVelX = +SNAKE_VEL;
                    break;
            }
        }
    } else {
        // Key pressed down
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            switch (event.key.keysym.sym) {
                case SDLK_y:
                    start();
                    break;
            }
        }
    }
}

bool Snake::move(int width, int height) {
    hit = false;
    
    // Left or right
    mPosX += mVelX;
    //mPosX += SNAKE_VEL;
    
    // Check if the snake moved to far left or right
    if ((mPosX < SNAKE_WIDTH) || (mPosX > width)) {
        // Move back
        mPosX -= mVelX;
        
        hit = true;
        return false;
    }
    
    // Up or down
    mPosY += mVelY;
    
    // Check if the snake moved to far up or down
    if ((mPosY < SNAKE_HEIGHT) || (mPosY > height)) {
        // Move back
        mPosY -= mVelY;
        
        hit = true;
        return false;
    }
    
    return true;
}

void Snake::render(SDL_Renderer* renderer) {
    // Draw snake
    SDL_Rect snake = {mPosX - SNAKE_WIDTH, mPosY - SNAKE_HEIGHT, SNAKE_WIDTH, SNAKE_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &snake);
}

SDL_Rect Snake::returnRect() {
    SDL_Rect rRect;
    rRect.x = mPosX;
    rRect.y = mPosY;
    rRect.w = SNAKE_WIDTH;
    rRect.h = SNAKE_HEIGHT;
    
    return rRect;
}
