#include "TextureManager.h"

TextureManager::TextureManager() {
    menuBackground = {0};
    gameBackground = {0};
    gameOverBg     = {0};
    playerTexture  = {0};
    enemyTexture   = {0};
    bulletTexture  = {0};
    bossTexture    = {0};
    shootSound     = {0};
}

TextureManager::~TextureManager() {
    unloadTextures();
}

void TextureManager::loadTextures() {
    
    menuBackground = LoadTexture("assets/SOFER.png");
    gameBackground = LoadTexture("assets/gamebg.png");
    gameOverBg     = LoadTexture("assets/gameover.jpg");
    playerTexture  = LoadTexture("assets/cinnamon.png");
    enemyTexture   = LoadTexture("assets/enemy.png");
    bulletTexture  = LoadTexture("assets/carrot.png");
    bossTexture    = LoadTexture("assets/boss.png");
    shootSound     = LoadSound("assets/pew.wav");
}

void TextureManager::unloadTextures() {
    UnloadTexture(menuBackground);
    UnloadTexture(gameBackground);
    UnloadTexture(gameOverBg);
    UnloadTexture(playerTexture);
    UnloadTexture(enemyTexture);
    UnloadTexture(bulletTexture);
    UnloadTexture(bossTexture);
    UnloadSound(shootSound);
}