//
//  lib.h
//  mySnakeClone
//
//  Created by Andreas Petersson on 2017-02-23.
//  Copyright © 2017 Andreas Petersson. All rights reserved.
//

#ifndef lib_h
#define lib_h

#include <SDL2/SDL.h>

bool collisionDetector(SDL_Rect a, SDL_Rect b) {
    int leftA,   leftB;
    int rightA,  rightB;
    int topA,    topB;
    int bottomA, bottomB;
    
    leftA   = a.x;
    rightA  = a.x + a.w;
    topA    = a.y;
    bottomA = a.y + a.h;
    
    leftB   = b.x;
    rightB  = b.x + b.w;
    topB    = b.y;
    bottomB = b.y + b.h;
    
    if (bottomA <= topB) {
        return false;
    }
    
    if (topA >= bottomB) {
        return false;
    }
    
    if (rightA <= leftB) {
        return false;
    }
    
    if (leftA >= rightB) {
        return false;
    }
    
    return true;
}

#endif /* lib_h */
