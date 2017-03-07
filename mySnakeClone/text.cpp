
#include "text.h"


Text::Text() {
    mText = NULL;
    mTextWidth = 0;
    mTextHeight = 0;
}

Text::~Text() {
    deallocatesText();
}

bool Text::init() {
    // Initialize SDL_ttf
    if (TTF_Init() == -1) {
        std::cout << "Unable to initialize SDL_ttf! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return false;
    }
    return true;
}

bool Text::createImageFromString(SDL_Renderer* renderer, std::string textureText, SDL_Color textColor) {
    deallocatesText();
    
    SDL_Surface* textSurface = TTF_RenderText_Solid(mFont, textureText.c_str(), textColor);
    if (textSurface != NULL) {
        mText = SDL_CreateTextureFromSurface(renderer, textSurface);
        if(mText != NULL) {
            mTextWidth  = textSurface->w;
            mTextHeight = textSurface->h;
        } else {
            std::cout << "Are not able to create texture from renderd text! SDL Error: " << SDL_GetError() << std::endl;
        }
        
        SDL_FreeSurface(textSurface);
    } else {
        std::cout << "Can not render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
    }
    
    return mText != NULL;
}

void Text::deallocatesText() {
    // Free font
    TTF_CloseFont(mFont);
    mFont = NULL;
    
    if (mText != NULL) {
        SDL_DestroyTexture(mText);
        mText = NULL;
        mTextWidth = 0;
        mTextHeight = 0;
    }
    
    TTF_Quit();
}

void Text::renderText(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip) {
    SDL_Rect renderQuad = { x, y, mTextWidth, mTextHeight };
    
    if(clip != NULL) {
        renderQuad.w = clip->w;
        renderQuad.h = clip->h;
    }
    
    SDL_RenderCopyEx(renderer, mText, clip, &renderQuad, angle, center, flip);
}

bool Text::loadTtfFiles() {
    mFont = TTF_OpenFont("PxPlus_IBM_VGA8.ttf", 28);
    if (mFont == NULL) {
        std::cout << "Failed to load the font PxPlus_IBM_VGA8! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return false;
    }
    
    return true;
}
