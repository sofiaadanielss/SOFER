#include "Player.h"
#include "raylib.h"

Player::Player() : Entity(0.0f, 0.0f, 45, 45, 4.0f), lives(3), cooldown(0) {}

Player::Player(float x, float y)
    : Entity(x, y, 45, 45, 4.0f), lives(3), cooldown(0) {
}

void Player::moveLeft()  { x -= speed; }
void Player::moveRight() { x += speed; }

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
    DrawRectangle(x, y, width, height, BLUE);
}
