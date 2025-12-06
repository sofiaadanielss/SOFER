#ifndef BULLET_H
#define BULLET_H

#include "Entity.h"

class Bullet : public Entity {
public:
    Bullet(float x, float y, float speed);

    void update() override;
    void render() override;
};

#endif
