
#include "snake.h"

void Snake::setPos(int x, int y) {
    mPosX = x;
    mPosY = y;
}

void Snake::move(int width, int height) {
    hit = false;
    
    // Left or right
    //mPosX += mVelX;
    mPosX += SNAKE_VEL;
    
    // Check if the snake moved to far left or right
    if ((mPosX < 0) || (mPosX + SNAKE_WIDTH > width)) {
        // Move back
        if (!hit) {
            //mPosX -= mVelX;
            mPosX -= SNAKE_VEL;
            hit = true;
        } else {
            hit = false;
        }
    }
    
    // Up or down
    mPosY += mVelY;
    
    // Check if the snake moved to far up or down
    if ((mPosY < 0) || (mPosY + SNAKE_HEIGHT > height)) {
        // Move back
        if (!hit) {
            mPosY -= mVelY;
            hit = true;
        } else {
            hit = false;
        }
    }
}

void Snake::render(SDL_Renderer* renderer) {
    // Draw snake
    SDL_Rect snake = {mPosX - SNAKE_WIDTH, mPosY - SNAKE_HEIGHT, SNAKE_WIDTH, SNAKE_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &snake);
}
