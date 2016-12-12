/*
 TODO...
 
 * [done]create a window. size 640 480. black background.
 * [done]draw a white dot. SNAKE.
 * [done]center the snake dot
 * make the dot move on it's own.
 * [done]make snake move on user input
 * [done]add collision detection. stop snake dot move out of window
 * draw dot at random place on the window. RAT.
 * snake eat rat. rat disappear and draw new rat dot at random place
 * snake grow by one dot after eating rat.
 * game over when snake hits wall or it self

*/
#include "game.h"

//Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, const char * argv[]) {
    Game* g_game = new Game("Snake", 100, 100, SCREEN_WIDTH, SCREEN_HEIGHT, 0);
    
    if (g_game->init()) {
        while (g_game->running()) {
            g_game->handleEvents();
            g_game->update();
            g_game->render();
        }
    } else {
        std::cout << "Failed to initialize" << std::endl;
    }
    g_game->clean();
    
    return 0;
}
