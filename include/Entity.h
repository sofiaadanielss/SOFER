#ifndef ENTITY_H
#define ENTITY_H

#include "raylib.h"

class Entity {
protected:
    float x, y;
    float width, height;
    float speed;
    bool active;

public:
    Entity(float x, float y, float w, float h, float speed);
    virtual ~Entity() = default;

    virtual void update() = 0;
    virtual void render() = 0;

    float getX() const { return x; }
    float getY() const { return y; }
    float getWidth() const { return width; }
    float getHeight() const { return height; }

    bool isActive() const { return active; }
    void deactivate() { active = false; }

    Rectangle getBounds() const {
        return { x, y, width, height };
    }
};

#endif

