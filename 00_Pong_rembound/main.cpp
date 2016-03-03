// ------------------------------------------------------------
// Porting Pong From Flash To C++
// http://rembound.com/articles/porting-pong-from-flash-to-cpp
// (c) 2014 Rembound.com
// ------------------------------------------------------------

#include "main.h"

int main(int argc, char* argv[]) {
    // Create the game object
    Game* game = new Game();

    // Initialize and run the game
    if (game->Init()) {
        game->Run();
    }

    // Clean up
    delete game;
    return 0;
}
