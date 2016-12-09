#ifndef game_h
#define game_h

#include <iostream>

#include <SDL2/SDL.h>

#include "snake.h"

class Game {
public:
    Game(const char* title, int xpos, int ypos, int screenWidth, int screenHight, int flags):
    mRunning(true), mWindow(NULL), mRenderer(NULL), mTitle(title), mXpos(xpos), mYpos(ypos),
    mScreenWidth(screenWidth), mScreenHight(screenHight), mFlags(flags) {
        snake.setPos(screenWidth / 2, screenHight / 2); }
    
    ~Game() {}
    
    bool init();            // Init SDL
    void render();          // Render objects
    void update();          // Updates the screen
    void handleEvents();    // Handles user input
    void clean();           // Clean SDL at exit
    
    bool running() { return mRunning; }
    SDL_Renderer* gRenderer() const { return mRenderer; }
    
private:
    SDL_Window* mWindow;
    SDL_Renderer* mRenderer;
    
    bool mRunning;
    
    const char* mTitle;                 // Window title
    int mXpos, mYpos;                   // The X and Y offsets of the window
    int mScreenWidth, mScreenHight;     // The windows width and height
    int mFlags;                         // Window Flag
    
    Snake snake;
    
};

#endif 
