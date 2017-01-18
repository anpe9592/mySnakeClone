
#ifndef mouse_h
#define mouse_h

#include <iostream>
#include <vector>

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
    
    std::vector<SDL_Rect>& getCollider();   // Gets the collision boxes
    
    bool collisionChecker(std::vector<SDL_Rect>& a, std::vector<SDL_Rect>& b);  // Checks collision
    
private:
    int mPosX, mPosY;   // The X and Y offset of the mouse dot
    
    std::vector<SDL_Rect> mColliders;       // The snake's collision boxes
    void shiftColliders();                  // Moves the collision boxes relative to the snake's offset
    
    bool hit;
};

#endif
