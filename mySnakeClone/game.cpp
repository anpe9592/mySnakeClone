#include "game.h"

// Load media files
bool Game::loadMedia() {
    // Open the font
    mFont = TTF_OpenFont("PxPlus_IBM_VGA8.ttf", 28);
    if (mFont == NULL) {
        std::cout << "Failed to load the font PxPlus_IBM_VGA8! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return false;
    }
    
    return true;
}

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
                
                if (TTF_Init() == -1) {
                    std::cout << "Unable to initialize SDL_ttf! SDL_ttf Error: " << TTF_GetError() << std::endl;
                    return false;
                }
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
    text.renderText(mRenderer, (mScreenWidth - text.getTextWidth() ) / 2, 12);
    snake.render(mRenderer);
    mouse.render(mRenderer);
    
    // Update screen
    SDL_RenderPresent(mRenderer);
}

void Game::update() {
    // Set text to be rendered
    gameOverText.str(" ");
    
    // Render text
    SDL_Color textColor = { 0xFF, 0xFF, 0xFF, 0xFF };
    if (!text.createImageFromString(mRenderer, mFont, gameOverText.str().c_str(), textColor)) {
        std::cout << "Unable to render game over texture!" << std::endl;
    }
    
    // Move the snake
    if (!snake.move(mScreenWidth, mScreenHight, mouse.returnRect())) {
        gameOverText.str("Game Over! \nPlay againg press Y? \nQuit press N?");
        
        // Render text
        if (!text.createImageFromString(mRenderer, mFont, gameOverText.str().c_str(), textColor)) {
            std::cout << "Unable to render game over texture!" << std::endl;
        }
    }
    mouse.move(mScreenWidth, mScreenHight, snake.returnRect()); // Move the mouse
    
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
        
        if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
            switch (event.key.keysym.sym) {
                case SDLK_n:
                    mRunning = false;
                    break;
            }
        }
        
        // Handle input for the snake dot
        snake.handleEvent(event);
    }
}

void Game::clean() {
    text.deallocatesText();
    
    TTF_CloseFont(mFont);
    mFont = NULL;
    
    SDL_DestroyRenderer(mRenderer);
    SDL_DestroyWindow(mWindow);
    mWindow = NULL;
    mRenderer = NULL;
    
    TTF_Quit();
    SDL_Quit();
}
