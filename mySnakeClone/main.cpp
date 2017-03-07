
#include "game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, const char * argv[]) {
    Game* g_game = new Game("Snake", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    
    if (g_game->init()) {
        if (g_game->loadMedia()) {
            while (g_game->running()) {
                g_game->handleEvents();
                g_game->update();
                g_game->render();
            }
        } else {
            std::cout << "Failed to load media" << std::endl;
        }
    } else {
        std::cout << "Failed to initialize" << std::endl;
    }
    g_game->clean();
    
    return 0;
}
