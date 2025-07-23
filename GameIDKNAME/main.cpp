
#include <iostream>
#include "Game.h"

int main()
{
    Game game;

    while (game.Running())
    {
        game.Update();
        game.Render();
    }

    return 0;
}


