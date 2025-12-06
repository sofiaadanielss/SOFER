#ifndef COLLISION_MANAGER_H
#define COLLISION_MANAGER_H

#include <vector>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"
#include "Boss.h"

class CollisionManager {
public:
    static bool check(const Entity& a, const Entity& b);

    static void process(
        Player& player,
        std::vector<Bullet>& bullets,
        std::vector<Enemy*>& enemies,
        int& scoreIncrease,
        int& normalsKilled,
        bool& bossKilled
    );
};

#endif

