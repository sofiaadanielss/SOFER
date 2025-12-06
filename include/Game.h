
#ifndef GAME_H
#define GAME_H

#include "raylib.h"
#include "Player.h"
#include "ScoreBoard.h"
#include "TextureManager.h"

#include "Enemy.h"
#include "Bullet.h"
#include "CollisionManager.h"
#include "NormalEnemy.h"
#include "Boss.h"
#include "GameState.h" 

#include <vector>
#include <algorithm>

class Game {
private:
    GameState       currentState;
    TextureManager  textureManager;
    Player* player;
    std::vector<Enemy*> enemies;
    std::vector<Bullet> bullets;
    ScoreBoard scoreboard;
    Music menuMusic;
    bool musicPlaying;

    bool running;
    int normalSpawned;
    int normalKilled;
    bool bossSpawned;
    float spawnTimer;
    
    void handleInput();   
    void update();       
    void render();        
    void resetCoreGame(); 

    void playMenuMusic();
    void stopMenuMusic();

public:
    Game();

    void init();
    void gameLoop();
    
};

#endif
