#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"
#include "raylib.h"

class Bullet : public Entity {
    
public:
    Bullet(float x, float y, float speed);
    
    bool isActive() const { return active; }
    void deactivate() { active = false; }
    
    void update() override;
    void render() override;
};

#endif