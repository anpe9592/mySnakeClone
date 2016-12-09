#ifndef snake_h
#define snake_h

#include <iostream>

#include <SDL2/SDL.h>

class Snake {
public:
    Snake():
    mPosX(0), mPosY(0), mVelX(0), mVelY(0) { }
    
    void render(SDL_Renderer* renderer);
    
private:
    int mPosX, mPosY;
    int mVelX, mVelY;
};

#endif /* snake_hpp */
