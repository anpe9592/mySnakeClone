
#include "snake.h"

void Snake::setPos(int x, int y) {
    mPosX = x;
    mPosY = y;
}

void Snake::handleEvent(SDL_Event& event) {
    // Key pressed down
    if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
        switch (event.key.keysym.sym) {
            case SDLK_UP:    mVelY -= SNAKE_VEL; break;
            case SDLK_DOWN:  mVelY += SNAKE_VEL; break;
            case SDLK_LEFT:  mVelX -= SNAKE_VEL; break;
            case SDLK_RIGHT: mVelX += SNAKE_VEL; break;
        }
    }
}

void Snake::move(int width, int height) {
    hit = false;
    
    // Left or right
    mPosX += mVelX;
    //mPosX += SNAKE_VEL;
    
    // Check if the snake moved to far left or right
    if ((mPosX < 0) || (mPosX + SNAKE_WIDTH > width)) {
        // Move back
        if (!hit) {
            //mPosX -= mVelX;
            mPosX = 0;
            hit = true;
        } else {
            mPosX = 0;
            hit = false;
        }
    }
    
    hit = false;
    // Up or down
    mPosY += mVelY;
    
    // Check if the snake moved to far up or down
    if ((mPosY < 0) || (mPosY + SNAKE_HEIGHT > height)) {
        // Move back
        if (!hit) {
            //mPosY -= mVelY;
            mPosY = 0;
            hit = true;
        } else {
            mPosY = 0;
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
