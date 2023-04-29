
#include "raylib.h"

#include "game.hpp"

using game::Game;

int main()
{
    Game test;
    
    test.Initialise();
    test.RunLoop();
    test.ShutDown();
    
    return 0;
}
