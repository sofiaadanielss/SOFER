#include "Enemy.h"
#include "raylib.h"

Enemy::Enemy(float x, float y, int points, float speed)
    : Entity(x, y, 45, 45, speed), points(points), dropSpeed(speed) {}

void Enemy::update() {
    y += dropSpeed;
    if (y > 600) active = false;
}

void Enemy::render() {
    if (texture.id != 0) {
        float scale = 0.05f; 
        float scaledWidth  = texture.width * scale;
        float scaledHeight = texture.height * scale;
        DrawTextureEx(texture, (Vector2){x, y}, 0, scale, WHITE);
        width  = scaledWidth;
        height = scaledHeight;
    } else {
        DrawRectangle(x, y, width, height, RED);
    }
}
