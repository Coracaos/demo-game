#include "Tank.h"
#include <iostream>
#include <math.h>


Tank::Tank(Settings settings)
{
    width = settings.tank_width;
    height = settings.tank_height;
    x = settings.tank_x;
    y = settings.tank_y;
    rot = settings.tank_rot;
    speed = settings.tank_speed;
    shoot = false;
    //canon
    w = width/2.0f;
    h = height/2.0f;
    w_c = width/8.0f;
    h_c = height*0.75f;


    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;
}

void Tank::drawTank(){

    glPushMatrix();
    glTranslatef(x, y, 0);


    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(0.0,0.0);

    for(float ang = 0.0; ang< 2.1*M_PI; ang = ang + 0.001){
        float x = w*cos(ang);
        float y = w*sin(ang);
        glVertex2f(x,y);
    }

    glEnd();

    glRotatef(rot, 0.0, 0.0, 1.0);

    glColor3f(0.8,0.2,0.2);
    glBegin(GL_QUADS);
    glVertex2f(h_c, w_c);
    glVertex2f(h_c, -w_c);
    glVertex2f(0, -w_c);
    glVertex2f(0, w_c);
    glEnd();

    glPopMatrix();
}

Tank::~Tank()
{
    //dtor
}
