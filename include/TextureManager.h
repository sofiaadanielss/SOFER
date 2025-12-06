#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include "raylib.h"

class TextureManager {
private:
    Texture2D menuBackground;
    Texture2D gameOverBg;
    Texture2D playerTexture;
    Texture2D enemyTexture;
    Texture2D bulletTexture;
    Texture2D bossTexture;
    Texture2D gameBackground;
    
public:
    TextureManager();
    ~TextureManager();
    
    void loadTextures();
    void unloadTextures();
    
    Texture2D getMenuBackground() const { return menuBackground; }
    Texture2D getGameOverBg() const { return gameOverBg; }
    Texture2D getPlayerTexture() const { return playerTexture; }
    Texture2D getEnemyTexture() const { return enemyTexture; }
    Texture2D getBulletTexture() const { return bulletTexture; }
    Texture2D getBossTexture() const { return bossTexture; }
    Texture2D getGameBackground() const {return gameBackground; }
};

#endif