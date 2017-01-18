
#include <random>
#include "mouse.h"

int mouseRandPos(int pos) {
    // Seed with a real random value, if available
    std::random_device r;
    
    // Choose a random mean between 40 and pos
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(40, pos);
    
    return uniform_dist(e1);
}



Mouse::Mouse():
mPosX(0), mPosY(0), hit(false) {
    // Create the necessary SDL_Rects
    mColliders.resize(1);
    
    // Initialize the collision boxes' width and height
    mColliders[0].w = MOUSE_WIDTH;
    mColliders[0].h = MOUSE_HEIGHT;
    
    // Initialize colliders relative to position
    shiftColliders();
}

void Mouse::move(int width, int height) {
    hit = false;
    
    mPosX = mouseRandPos(width);
    mPosY = mouseRandPos(height);
}

void Mouse::render(SDL_Renderer* renderer) {
    // Draw mouse
    SDL_Rect mouse = {mPosX - MOUSE_WIDTH, mPosY - MOUSE_HEIGHT, MOUSE_WIDTH, MOUSE_HEIGHT};
    SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF);
    SDL_RenderFillRect(renderer, &mouse);
}



// checks collision
bool Mouse::collisionChecker(std::vector<SDL_Rect>& a, std::vector<SDL_Rect>& b) {
    // The rectangles sides
    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;
    
    // Go through A boxes
    for (int Abox = 0; Abox < a.size(); Abox++) {
        // Calculate ract A sides
        leftA = a[Abox].x;
        rightA = a[Abox].x + a[Abox].w;
        topA = a[Abox].y;
        bottomA = a[Abox].y + a[Abox].h;
        
        // Go through A boxes
        for (int Bbox = 0; Bbox < b.size(); Bbox++) {
            // Calculate ract B sides
            leftB = b[Bbox].x;
            rightB = b[Bbox].x + b[Bbox].w;
            topB = b[Bbox].y;
            bottomB = b[Bbox].y + b[Bbox].h;
            
            // Check if no sides from A are outside of B
            if (((bottomA <= topB) || (topA >= bottomB) || (rightA <= leftB) || (leftA >= rightB)) == false) {
                /*
                 if (Bbox == 0) {
                 mVelY = -8;
                 }
                 if (Bbox == 1) {
                 mVelY = -4;
                 }
                 if (Bbox == 2) {
                 mVelY = -2;
                 }
                 if (Bbox == 3) {
                 mVelY = 2;
                 }
                 if (Bbox == 4) {
                 mVelY = 4;
                 }
                 if (Bbox == 5) {
                 mVelY = 8;
                 }
                 */
                // Collision is detected
                return true;
            }
        }
    }
    
    // No collision detected
    return false;
}

std::vector<SDL_Rect>& Mouse::getCollider() {
    return mColliders;
}

void Mouse::shiftColliders() {
    // Row offset
    int r = 0;
    
    // Moving through the mouses collision boxes
    for (int set = 0; set < mColliders.size(); ++set) {
        // Center the collision box
        mColliders[set].x = mPosX + (MOUSE_WIDTH - mColliders[set].w) / 2;
        
        // Set the collision box at its row offset
        mColliders[set].y = mPosY + r;
        
        // Move the row offset down the height of the collision box
        r += mColliders[set].h;
    }
}
