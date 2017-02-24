#ifndef snake_h
#define snake_h

#include <iostream>
#include <vector>
#include <random>

#include <SDL2/SDL.h>

class Snake {
public:
    Snake():
    mPosX(0), mPosY(0), mVelX(0), mVelY(0), hit(false), eat(true), key(0) {
        start();
        mCollisionBox.w = SNAKE_WIDTH;
        mCollisionBox.h = SNAKE_HEIGHT;
    }
    
    bool collisionDetector(SDL_Rect a, SDL_Rect b);
    void setPos(int x, int y);
    void start();
    void direction(int x, int y);
    
    void handleEvent(SDL_Event& event);     // Takes key input and adept the snakes velocity
    bool move(int width, int height, SDL_Rect mouse);       // Move the snake
    void render(SDL_Renderer* renderer);    // Draw snake on to screen
    
    static const int SNAKE_WIDTH  = 20;     // Snake dot width
    static const int SNAKE_HEIGHT = 20;     // Snake dot height
    static const int SNAKE_VEL    =  3;     // Max velocity of the snake
    
    SDL_Rect returnRect();
    
private:
    int mPosX, mPosY;       // The X and Y offset of the snake dot
    int mVelX, mVelY;       // The velocity of the snake
    int mConstX, mConstY;   // The constant X and Y start position
    
    bool hit;
    bool eat;
    
    SDL_Rect mCollisionBox;
    
    int key;
    
    std::vector<SDL_Rect> snakeDots;
};

#endif 
