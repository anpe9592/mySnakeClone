#ifndef snake_h
#define snake_h

#include <iostream>

#include <SDL2/SDL.h>

class Snake {
public:
    Snake():
    mPosX(0), mPosY(0), mVelX(0), mVelY(0), hit(false) { }
    
    void setPos(int x, int y);
    
    void handleEvent(SDL_Event& event);     // Takes key input and adept the snakes velocity
    void move(int width, int height);       // Move the snake
    void render(SDL_Renderer* renderer);    // Draw snake on to screen
    
    static const int SNAKE_WIDTH  = 20;     // Snake dot width
    static const int SNAKE_HEIGHT = 20;     // Snake dot height
    static const int SNAKE_VEL    =  5;     // Max velocity of the snake
    
private:
    int mPosX, mPosY;   // The X and Y offset of the snake dot
    int mVelX, mVelY;   // The velocity of the snake
    
    bool hit;
};

#endif 
