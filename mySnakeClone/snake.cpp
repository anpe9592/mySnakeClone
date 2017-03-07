
#include "snake.h"

bool Snake::collisionDetector(SDL_Rect a, SDL_Rect b) {
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

void Snake::setPos(int x, int y) {
    mPosX = x;
    mPosY = y;
    mConstX = x;
    mConstY = y;
}

void Snake::start() {
    snakeDots.clear();
    eat = true;
    
    // Seed with a real random value, if available
    std::random_device r;
    
    // Choose a random mean between 1 and 4
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(1, 4);
    int directions = uniform_dist(e1);
    
    if (directions == 1) { // right
        key = 4;
        direction(SNAKE_VEL, 0);
    } else if (directions == 2) { // left
        key = 3;
        direction(-SNAKE_VEL, 0);
    } else if (directions == 3) { // down
        key = 2;
        direction(0, SNAKE_VEL);
    } else { // up
        key = 1;
        direction(0, -SNAKE_VEL);
    }
}

void Snake::direction(int x, int y) {
    mPosX = mConstX;
    mPosY = mConstY;
    mVelX = x;
    mVelY = y;
    hit = false;
}

void Snake::handleEvent(SDL_Event& event) {
    if (!hit) {
        // Key pressed down
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            switch (event.key.keysym.sym) {
                case SDLK_UP:
                    std::cout << "up " << SDLK_UP << std::endl;
                    key = 1;
                    mVelX = 0;
                    mVelY = -SNAKE_VEL;
                    break;
                case SDLK_DOWN:
                    std::cout << "down " << SDLK_DOWN << std::endl;
                    key = 2;
                    mVelX = 0;
                    mVelY = +SNAKE_VEL;
                    break;
                case SDLK_LEFT:
                    std::cout << "left " <<  SDLK_LEFT << std::endl;
                    key = 3;
                    mVelY = 0;
                    mVelX = -SNAKE_VEL;
                    break;
                case SDLK_RIGHT:
                    std::cout << "right " <<  SDLK_RIGHT << std::endl;
                    key = 4;
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

bool Snake::move(int width, int height, SDL_Rect mouse) {
    hit = false;
    
    // Left or right
    mPosX += mVelX;
    //mPosX += SNAKE_VEL;
    
    // Check if the snake moved to far left or right
    if ((mPosX < 0) || (mPosX + SNAKE_WIDTH > width)) {
        // Move back
        mPosX -= mVelX;
        
        hit = true;
        return false;
    }
    
    // Up or down
    mPosY += mVelY;
    
    // Check if the snake moved to far up or down
    if ((mPosY < 0) || (mPosY + SNAKE_HEIGHT > height)) {
        // Move back
        mPosY -= mVelY;
        
        hit = true;
        return false;
    }
    
    mCollisionBox.x = mPosX;
    mCollisionBox.y = mPosY;
    
    if (collisionDetector(mCollisionBox, mouse)) {
        //mPosX = mouseRandPos(width);
        //mPosY = mouseRandPos(height);
        eat = true;
        
        std::cout << "I ate you" << std::endl;
        
        mCollisionBox.x = mPosX;
        mCollisionBox.y = mPosY;
    }
    
    return true;
}

void Snake::render(SDL_Renderer* renderer) {
    // creats a snake dot
    if (eat == true) {
        for (int i = 0; i < 5; i++) {
            SDL_Rect snake = {mPosX, mPosY, SNAKE_WIDTH, SNAKE_HEIGHT};
            snakeDots.push_back(snake);
        }
        eat = false;
    }
    
    //std::cout << snakeDots[0].x << std::endl;
    
    // Draw snake
    int oldPosX = mPosX;
    int oldPosY = mPosY;
    for (int i = 0; i < snakeDots.size(); i++) {
        int tmpX = snakeDots[i].x;
        int tmpY = snakeDots[i].y;
        
        snakeDots[i].x = oldPosX;
        snakeDots[i].y = oldPosY;
        
        oldPosX = tmpX;
        oldPosY = tmpY;
        
        SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
        SDL_RenderFillRect(renderer, &snakeDots[i]);
    }
    /*
    SDL_Rect snake = {mPosX - SNAKE_WIDTH, mPosY - SNAKE_HEIGHT, SNAKE_WIDTH, SNAKE_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &snake);
    */
}

SDL_Rect Snake::returnRect() {
    SDL_Rect rRect;
    rRect.x = mPosX;
    rRect.y = mPosY;
    rRect.w = SNAKE_WIDTH;
    rRect.h = SNAKE_HEIGHT;
    
    return rRect;
}
