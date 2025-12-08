#include "../include/Game.h"

int main()
{
    Game game;
    
    game.init();
    game.gameLoop();

    GameState state = GameState::MENU;
    return 0;
}