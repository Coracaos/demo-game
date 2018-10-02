#ifndef BULLET_H
#define BULLET_H
#include "Settings.h"
#include "Tank.h"
#include <math.h>
#include <GL/glut.h>
#include <iostream>

class Bullet
{
    public:
        float radius;
        float x;
        float y;
        float speed;
        float direction;

        Bullet(Settings, Tank);
        void drawBullet();
        virtual ~Bullet();

    protected:

    private:
};

#endif // BULLET_H
