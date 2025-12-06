#include "CollisionManager.h"
#include "raylib.h"

bool CollisionManager::check(const Entity& a, const Entity& b) {
    return CheckCollisionRecs(a.getBounds(), b.getBounds());
}

void CollisionManager::process(
    Player& player,
    std::vector<Bullet>& bullets,
    std::vector<Enemy*>& enemies,
    int& scoreIncrease,
    int& normalsKilled,
    bool& bossKilled
) {

    for (auto& b : bullets) {
        if (!b.isActive()) continue;

        for (auto* e : enemies) {
            if (!e->isActive()) continue;

            if (check(b, *e)) {
                b.deactivate();

                Boss* boss = dynamic_cast<Boss*>(e);
                if (boss) {
                    if (boss->takeHit()) {
                        scoreIncrease += 100;
                        bossKilled = true;
                    }
                } else {
                    normalsKilled++;
                    scoreIncrease += e->getPoints();
                    e->deactivate();
                }
                break;
            }
        }
    }
}




