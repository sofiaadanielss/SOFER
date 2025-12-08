#include "Bullet.h"
#include "raylib.h"

Bullet::Bullet(float x, float y, float speed)
    : Entity(x, y, 6, 12, speed) {}


void Bullet::update() {
    y -= speed;
    if (y < -20) active = false;
}

void Bullet::render() {
    DrawRectangle(x, y, width, height, ORANGE);
}
