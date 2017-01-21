#include "game.h"

bool Game::init() {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        // Set texture filtering to linear
        if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) {
            std::cout << "Warning: Linear texture filtering is disabled!" << std::endl;
        }
        
        // Creating the window
        mWindow = SDL_CreateWindow(mTitle, mXpos, mYpos, mScreenWidth, mScreenHight, mFlags);
        if (mWindow != NULL) {
            // Vsynced renderer is created for the window
            mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
            if (mRenderer != NULL) {
                // Initialize renderer color
                SDL_SetRenderDrawColor(mRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
            } else {
                std::cout << "Unable to create Renderer! SDL Error: " << SDL_GetError() << std::endl;
                return false;
            }
        } else {
            std::cout << "Unable to create Window! SDL Error: " << SDL_GetError() << std::endl;
            return false;
        }
    } else {
        std::cout << "Unable to initialize SDL! SDL Error: " << SDL_GetError() << std::endl;
        return false;
    }
    
    return true;
}

void Game::render() {
    // Render objects
    snake.render(mRenderer);
    mouse.render(mRenderer);
    
    // Update screen
    SDL_RenderPresent(mRenderer);
}

void Game::update() {
    //tmp
    SDL_Rect snakes;
    snakes.x = 300;
    snakes.y = 40;
    snakes.w = 40;
    snakes.h = 400;
    //tmp
    
    snake.move(mScreenWidth, mScreenHight); // Move the snake
    mouse.move(mScreenWidth, mScreenHight, snakes); // Move the mouse
    
    // Clear screen
    SDL_SetRenderDrawColor(mRenderer, 0x00, 0x00, 0x00, 0x00);
    SDL_RenderClear(mRenderer);
}

void Game::handleEvents() {
    SDL_Event event;
    
    while (SDL_PollEvent(&event) != 0) {
        // User requests quit
        if (event.type == SDL_QUIT) {
            mRunning = false;
        }
        
        // Handle input for the snake dot
        snake.handleEvent(event);
    }
}

void Game::clean() {
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    mWindow = NULL;
    mRenderer = NULL;
    
    SDL_Quit();
}
