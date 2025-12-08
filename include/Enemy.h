#ifndef ENEMY_H
#define ENEMY_H

#include "Entity.h"

class Enemy : public Entity {
protected:
    int points;
    float dropSpeed;
    Texture2D texture;
public:
    Enemy(float x, float y, int points, float speed);
    void setTexture(Texture2D tex) { texture = tex; }
    
    void update() override;
    void render() override;

    int getPoints() const { return points; }
};

#endif
