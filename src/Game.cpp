#include "Game.h"
#include "MenuScreen.h"  
#include <algorithm>

Game::Game() 
    : currentState(MENU),           
      textureManager(),           
      menuMusic({0}), 
      gameMusic({0}),  
      currentMusic(nullptr),             
      musicPlaying(false),          
      player(nullptr),            
      enemies(),                    
      bullets(),                    
      scoreboard(),               
      running(true),           
      normalSpawned(0),       
      normalKilled(0),         
      bossSpawned(false),       
      spawnTimer(0) {              
}

void Game::init() {

    InitWindow(800, 600, "SoferBlast");
    SetTargetFPS(60);
    
    Image icon = LoadImage("assets/logo.png");
    SetWindowIcon(icon);
    UnloadImage(icon); 

    InitAudioDevice();
    textureManager.loadTextures();

    menuMusic = LoadMusicStream("assets/piano.wav"); 
    gameMusic = LoadMusicStream("assets/game.wav");
    
    player = new Player(380, 500);
    player->setTexture(textureManager.getPlayerTexture());

    musicPlaying = false;
}

void Game::playMenuMusic() {
    if (currentMusic != &menuMusic) {
        if (currentMusic && musicPlaying) {
            StopMusicStream(*currentMusic);
        }
        
        PlayMusicStream(menuMusic);
        currentMusic = &menuMusic;
        musicPlaying = true;
    }
}

void Game::stopMenuMusic() {
    if (currentMusic == &menuMusic && musicPlaying) {
        StopMusicStream(menuMusic);
        currentMusic = nullptr;
        musicPlaying = false;
    }
}

void Game::playGameMusic() {
    if (currentMusic != &gameMusic) {
        if (currentMusic && musicPlaying) {
            StopMusicStream(*currentMusic);
        }
        
        PlayMusicStream(gameMusic);
        currentMusic = &gameMusic;
        musicPlaying = true;
    }
}

void Game::stopGameMusic() {
    if (currentMusic == &gameMusic && musicPlaying) {
        StopMusicStream(gameMusic);
        currentMusic = nullptr;
        musicPlaying = false;
    }
}

void Game::resetCoreGame() {
    for (auto e : enemies) delete e;
    enemies.clear();
    
    bullets.clear();
    
    if (player) {
        delete player;
        player = new Player(380, 500);
    }
    
    spawnTimer = 0;
    normalSpawned = 0;
    normalKilled = 0;
    bossSpawned = false;
    running = true;
}

void Game::handleInput() {
    if (IsKeyPressed(KEY_P)) {
        currentState = (currentState == PLAYING) ? PAUSED : PLAYING;
        return;
    }
    
    if (currentState == PLAYING) {
        if (IsKeyDown(KEY_LEFT))  player->moveLeft();
        if (IsKeyDown(KEY_RIGHT)) player->moveRight();
        
        if (IsKeyPressed(KEY_SPACE) && player->canShoot()) {
            bullets.emplace_back(
                player->getX() + player->getWidth()/2 - 3,
                player->getY(),
                7.0f
            );
            
            PlaySound(textureManager.getShootSound());
        }
    }
}

void Game::update() {    
    if (currentState != PLAYING) return;

    spawnTimer += GetFrameTime();
    if (!bossSpawned && normalSpawned < 20) {
        if (spawnTimer >= 1.0f) {
            auto* e = new NormalEnemy(GetRandomValue(50, 750), 20);
            e->setTexture(textureManager.getEnemyTexture());
            enemies.push_back(e);
            normalSpawned++;
            spawnTimer = 0.0f;
        }
    }

    
    if (!bossSpawned && normalKilled >= 20) {
        auto* boss = new Boss(350, 40);
        boss->setTexture(textureManager.getBossTexture());
        enemies.push_back(boss);
        bossSpawned = true;
    }
    
    player->update();
    for (auto& b : bullets) b.update();
    for (auto& e : enemies) e->update();
    
    int scoreIncrease = 0;
    int killedFrame = 0;
    bool bossKilled = false;
    
    CollisionManager::process(*player, bullets, enemies, scoreIncrease, killedFrame, bossKilled);
    
    scoreboard.addPoints(scoreIncrease);
    normalKilled += killedFrame;
    
    if (bossSpawned && bossKilled) {
        bossSpawned = false;
        spawnTimer = 0;
        normalSpawned = 0;
        normalKilled = 0;
    }
    
    for (auto* e : enemies) {
        if (!e->isActive()) continue;
        
        if (e->getY() + e->getHeight() >= 600) {
            player->takeDamage();
            e->deactivate();
        }
    }
    
    enemies.erase(
        std::remove_if(enemies.begin(), enemies.end(),
            [](Enemy* e){
                if (!e->isActive()) {
                    delete e;
                    return true;
                }
                return false;
            }),
        enemies.end()
    );
    
    bullets.erase(
        std::remove_if(bullets.begin(), bullets.end(),
            [](Bullet& b){ return !b.isActive(); }),
        bullets.end()
    );
    
    if (player->getLives() <= 0) {
        running = false;
        currentState = GAME_OVER;
        stopMenuMusic();
    }
}

void Game::render() {
    BeginDrawing();
    ClearBackground(BLACK);
    if (currentState == PLAYING) {
        player->render();
        scoreboard.render();
        
        DrawText(TextFormat("Lives: %d", player->getLives()), 10, 10, 20, WHITE);
        
        for (auto& b : bullets) b.render();
        for (auto& e : enemies) e->render();
    }
    
    EndDrawing();
}

void Game::gameLoop() {
    while (!WindowShouldClose()) {
        if (musicPlaying && currentMusic) {
            UpdateMusicStream(*currentMusic);
        }
        switch (currentState) {
            case MENU:
                playMenuMusic();
                UpdateMusicStream(menuMusic);
                UpdateMenu(currentState);  
                BeginDrawing();
                ClearBackground(BLACK);
                DrawMenu(textureManager.getMenuBackground());  
                DrawText("SOFER BLAST", 160, 185, 75, PINK);
                DrawText("Press ENTER to Start", 215, 275, 30, MAGENTA);
                DrawText("Use < and > to move", 295, 330, 25, SKYBLUE);
                EndDrawing();
                break;
                
            case PLAYING:
                BeginDrawing();
                ClearBackground(BLACK);
                DrawMenu(textureManager.getGameBackground());  
                playGameMusic();
                handleInput();
                update();
                render();
                EndDrawing();
                break;
                
            case GAME_OVER:
                BeginDrawing();
                ClearBackground(BLACK);
                DrawTexture(textureManager.getGameOverBg(),0,0,WHITE);
                DrawText("GAME OVER", 230, 200, 60, RED);
                DrawText("Press ENTER to play again.", 175, 330, 35, WHITE);
                DrawText(TextFormat("Final Score: %d", scoreboard.getScore()), 290, 400, 30, YELLOW);
                EndDrawing();
                
                if (IsKeyPressed(KEY_ENTER)) {
                    resetCoreGame();
                    scoreboard.reset();
                    currentState = MENU;
                }
                break;
                
            case PAUSED:
                BeginDrawing();
                ClearBackground(BLACK);
                DrawText("GAME PAUSED", 250, 250, 40, PINK);
                DrawText("Press P to Resume", 250, 350, 30, MAGENTA);
                EndDrawing();
                
                if (IsKeyPressed(KEY_P)) {
                    currentState = PLAYING;
                }
                break;
        }
    }
    
    stopMenuMusic();
    UnloadMusicStream(menuMusic);
    UnloadMusicStream(gameMusic);
    CloseAudioDevice();
    CloseWindow();
}