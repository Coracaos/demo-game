//g++ main.cpp -o main -lGL -lGLU -lglut
#include <windows.h>
#include <GL/glut.h>
#include "Game.h"
#include "Settings.h"
#include "Tank.h"
#include <iostream>
#include <math.h>
#include <vector>
#include "Bullet.h"

using namespace std;

Settings settings;
Game game;
Tank tank(settings);
vector<Bullet> bullets;

void update();
void reProyectar(int w, int h);
void keyPress(unsigned char key, int x, int y);
void keyRelease(unsigned char key, int x, int y);
void checkEvents(int value);
void mouseClicked(int button, int state, int x, int y);
void mouseAction(int x, int y);


int main(int argc, char **argv)
{
    // Init library glut
    glutInit(&argc, argv);
    // Initial set mode display
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);

    glutInitWindowPosition((int) settings.screen_x, (int) settings.screen_y);
    glutInitWindowSize((int)settings.screen_width, (int) settings.screen_height);

    glutCreateWindow(settings.game_title.c_str());

    //display screen
    glutDisplayFunc(update);

    glutIgnoreKeyRepeat(1);
    glutKeyboardFunc(keyPress);
    glutKeyboardUpFunc(keyRelease);
    glutMouseFunc(mouseClicked);
    glutPassiveMotionFunc(mouseAction);

    glutReshapeFunc(reProyectar);

    glutTimerFunc(16.666, checkEvents, 0);
    //Main Loop - call glutDisplayFunc
    glutMainLoop();

    return 0;
}

void update()
{
    game.updateScreen(&tank, bullets);
}

void reProyectar(int w, int h) {

    GLfloat formato;
    if(h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    formato = (GLfloat)w / (GLfloat)h;

    if (w <= h){
        settings.screen_top = 340.0f / formato;
        settings.screen_bottom = -340.0f / formato;
        glOrtho ((GLfloat) settings.screen_left, (GLfloat) settings.screen_right, (GLfloat) settings.screen_bottom, (GLfloat) settings.screen_top, 1.0f, -1.0f);
    }else{
        settings.screen_left = -340.0f * formato;
        settings.screen_right = 340.0f * formato;
        glOrtho ((GLfloat) settings.screen_left, (GLfloat) settings.screen_right, (GLfloat) settings.screen_bottom, (GLfloat) settings.screen_top, 1.0f, -1.0f);
    }
}

void keyPress(unsigned char key, int x, int y){
    game.keyPressGame(key, &tank);
}

void keyRelease(unsigned char key, int x, int y) {
    game.keyReleaseGame(key, &tank);
}

void checkEvents(int value){
    game.checkEventsGame(&tank, bullets, settings);
    glutPostRedisplay();
    glutTimerFunc(16.666, checkEvents, value);
}

void mouseAction(int x, int y){
    float mx = (settings.screen_left + x) - tank.x;
    float my = (settings.screen_top - y) - tank.y;
    tank.rot = (atan2(my,mx)*180)/M_PI;
}

void mouseClicked(int button, int state, int x, int y){
    if(state == GLUT_DOWN) tank.shoot = true;
}

