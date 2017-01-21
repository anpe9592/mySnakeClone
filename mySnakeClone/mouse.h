
#ifndef mouse_h
#define mouse_h

#include <iostream>

#include <SDL2/SDL.h>

class Mouse {
public:
    Mouse();
    
    void setPos(int x, int y);
    
    void handleEvent(SDL_Event& event);     // Takes key input and adept the mouse velocity
    void move(int width, int height);       // Move the mouse
    void render(SDL_Renderer* renderer);    // Draw mouse on to screen
    
    static const int MOUSE_WIDTH  = 20;     // Mouse dot width
    static const int MOUSE_HEIGHT = 20;     // Mouse dot height
    
private:
    int mPosX, mPosY;   // The X and Y offset of the mouse dot
    
    bool hit;
    
    SDL_Rect mCollisionBox;
};

#endif
