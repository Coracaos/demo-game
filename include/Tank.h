#ifndef TANK_H
#define TANK_H

#include <windows.h>
#include <GL/glut.h>
#include "Settings.h"


class Tank
{
    public:
        float width;
        float height;
        float x;
        float y;
        float rot;

        float speed;

        bool up;
        bool down;
        bool left;
        bool right;

        bool shoot;

        float w;
        float h;
        float w_c;
        float h_c;

        Tank(Settings);
        void drawTank();
        virtual ~Tank();

    protected:

    private:
};

#endif // TANK_H
