#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"

class Player : public Entity {
    int lives;
    int cooldown;

public:
    Player();
    Player(float x, float y);

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
