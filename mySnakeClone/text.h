
#ifndef text_h
#define text_h

#include <iostream>
#include <string>

#include <SDL2/SDL.h>
#include <SDL2_ttf/SDL_ttf.h>

class Text {
public:
    Text();
    
    ~Text();
    
    bool createImageFromString(SDL_Renderer* renderer, TTF_Font *font, std::string textureText, SDL_Color textColor);
    
    void deallocatesText();
    
    void renderText(SDL_Renderer* renderer, int x, int y, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);
    
    int getTextWidth()  const { return mTextWidth; }
    int getTextHeight() const { return mTextHeight; }
    
private:
    SDL_Texture* mText;
    
    int mTextWidth;
    int mTextHeight;
};

#endif
