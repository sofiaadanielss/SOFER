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
    if (texture.id != 0) {
        float scale = 0.2f; 
        float scaledWidth  = texture.width * scale;
        float scaledHeight = texture.height * scale;
        DrawTextureEx(texture, (Vector2){x, y}, 0, scale, WHITE);
        width  = scaledWidth + 20;
        height = scaledHeight + 20;
    } else {
        DrawRectangle(x, y, width + 20, height + 20, PURPLE);
    }
}
