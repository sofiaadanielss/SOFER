#include "Boss.h"
#include "raylib.h"

Boss::Boss(float x, float y)
    : Enemy(x, y, 100, 0.6f), hp(7) {}

void Boss::update() {
    y += dropSpeed;
    if (y > 600) active = false;
}

bool Boss::takeHit() {
    hp--;
    if (hp <= 0) {
        deactivate();
        return true;
    }
    return false;
}

void Boss::render() {
    DrawRectangle(x, y, width + 20, height + 20, PURPLE);
}
