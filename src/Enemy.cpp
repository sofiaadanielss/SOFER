#include "Enemy.h"
#include "raylib.h"

Enemy::Enemy(float x, float y, int points, float speed)
    : Entity(x, y, 45, 45, speed), points(points), dropSpeed(speed) {}

void Enemy::update() {
    y += dropSpeed;
    if (y > 600) active = false;
}

void Enemy::render() {
    DrawRectangle(x, y, width, height, RED);
}
