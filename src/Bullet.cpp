#include "Bullet.h"


Bullet::Bullet(Settings settings, Tank tank)
{
    radius = settings.bullet_radius;
    direction = tank.rot*M_PI/180;
    x = tank.x + 30*cos(direction);
    y = tank.y + 30*sin(direction);
    speed = settings.bullet_speed;
}

void Bullet::drawBullet(){

    float a,b;

    glColor3f(0.8F, 0.0f, 0.0f);

    glBegin(GL_TRIANGLE_FAN);

    glVertex2f(x,y);

    for(float ang = 0.0; ang< 2.1*M_PI; ang+=0.001){
        a = radius*cos(ang) + x;
        b = radius*sin(ang) + y;
        glVertex2f(a, b);
    }

    glEnd();


}

Bullet::~Bullet()
{

}
