#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "raylib.h"

class Player : public Entity {
    int lives;
    int cooldown;
    Texture2D texture;

public:
    Player();
    Player(float x, float y);

    void setTexture(Texture2D player);

    void moveLeft();
    void moveRight();
    bool canShoot();
    void takeDamage();
    int getLives() const { return lives; }
    bool isAlive() const;

    void update() override;
    void render() override;
};

#endif
