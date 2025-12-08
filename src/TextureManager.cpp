#include "TextureManager.h"

TextureManager::TextureManager() {
    menuBackground = {0};
    gameOverBg     = {0};
    playerTexture  = {0};
    enemyTexture   = {0};
    bulletTexture  = {0};
    bossTexture    = {0};
    gameBackground = {0};
    shootSound     = {0};
}

TextureManager::~TextureManager() {
    unloadTextures();
}

void TextureManager::loadTextures() {
    
    menuBackground = LoadTexture("assets/menu.png");
    gameOverBg     = LoadTexture("assets/gameover.jpg");
    playerTexture  = LoadTexture("assets/cinnamon.png");
    enemyTexture   = LoadTexture("assets/enemy.png");
    bulletTexture  = LoadTexture("assets/carrot.png");
    bossTexture    = LoadTexture("assets/boss.png");
    gameBackground = LoadTexture("assets/game.png");
    shootSound     = LoadSound("assets/pew.wav");
}

void TextureManager::unloadTextures() {
    UnloadTexture(menuBackground);
    UnloadTexture(gameOverBg);
    UnloadTexture(playerTexture);
    UnloadTexture(enemyTexture);
    UnloadTexture(bulletTexture);
    UnloadTexture(bossTexture);
    UnloadTexture(gameBackground);
    UnloadSound(shootSound);
}