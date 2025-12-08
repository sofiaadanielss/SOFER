#include "Player.h"

Player::Player() : Entity(0.0f, 0.0f, 45, 45, 4.0f), lives(3), cooldown(0) {
    texture = {0};
}

Player::Player(float x, float y)
    : Entity(x, y, 45, 45, 4.0f), lives(3), cooldown(0) {
        texture = {0};
}

void Player::setTexture(Texture2D player) {
    texture = player;
}

void Player::moveLeft()  { 
    x -= speed; 
}
void Player::moveRight() { 
    x += speed; 
}

bool Player::canShoot() 
{
    if (cooldown == 0) 
    {
        cooldown = 15;
        return true;
    }
    return false;
}

void Player::takeDamage() {
    lives--;
}

bool Player::isAlive() const{
    return lives>0;
}

void Player::update() {
    if (cooldown > 0) cooldown--;
}

void Player::render() {
    if (texture.id != 0) {  
        float scale = 0.1f;
        float scaledWidth = texture.width * scale;
        float scaledHeight = texture.height * scale;

        DrawTextureEx(texture,(Vector2){x, y},0, scale, WHITE);
        
        width = scaledWidth;
        height = scaledHeight;
    } else {
        DrawRectangle(x, y, width, height, BLUE);
    }
}
