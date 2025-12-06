#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"

class Boss : public Enemy {
    int hp;

public:
    Boss(float x, float y);

    void update() override;
    void render() override;

    bool takeHit();
};

#endif
