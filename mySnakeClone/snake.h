#ifndef snake_h
#define snake_h

#include <iostream>

#include <SDL2/SDL.h>

class Snake {
public:
    Snake():
    mPosX(0), mPosY(0), mVelX(0), mVelY(0) { }
    
    void render(SDL_Renderer* renderer);
    
    static const int SNAKE_WIDTH = 20;
    static const int SNAKE_HEIGHT = 20;
    
private:
    int mPosX, mPosY;
    int mVelX, mVelY;
};

#endif 
