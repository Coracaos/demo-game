#include "Game.h"
#include <iostream>

using namespace std;

Game::Game()
{

}

void Game::updateScreen(Tank * tank, vector <Bullet>& bullets){

    // Set clear color
    glClearColor(0,1,0,1);
	// Clear screen
    glClear(GL_COLOR_BUFFER_BIT);

    tank->drawTank();

    for(int i=0; i<bullets.size(); i++){
        bullets[i].drawBullet();
    }
	// Change buffer
    // Render buffer in the screen
	glutSwapBuffers();
}

void Game::keyPressGame(unsigned char key, Tank *tank){

    switch(key){

        case 'a':
            tank->left = true;
            break;

        case 'd':
            tank->right = true;
            break;

        case 'w':
            tank->up = true;
            break;

        case 's':
            tank->down = true;
            break;

        default:
            break;
    }
}

void Game::keyReleaseGame(unsigned char key, Tank *tank){

    switch(key){

        case 'a':
            tank->left = false;
            break;

        case 'd':
            tank->right = false;
            break;

        case 'w':
            tank->up = false;
            break;

        case 's':
            tank->down = false;
            break;

        default:
            break;
    }
}

void Game::checkEventsGame(Tank * tank, std::vector<Bullet>& bullets, Settings settings){
    checkEventsTank(tank, bullets, settings);
    checkEventsBullet(bullets, settings);
}

void Game::checkEventsTank(Tank * tank, vector<Bullet>& bullets, Settings settings){

    if((tank->right && tank->left) || (tank->up && tank->down)){

    }else if(tank->right){
        tank->x += tank->speed;
    }else if(tank->left){
        tank->x -= tank->speed;
    }else if(tank->up){
        tank->y += tank->speed;
    }else if(tank->down){
        tank->y -= tank->speed;
    }

    if(tank->shoot){
        Bullet new_bullet(settings, *tank);
        bullets.push_back(new_bullet);
        tank->shoot = false;
    }
}

void Game::checkEventsBullet(vector <Bullet>& bullets, Settings settings){
    for(int i = 0; i< bullets.size(); i++){
        bullets[i].x += 5.0*cos(bullets[i].direction);
        bullets[i].y += 5.0*sin(bullets[i].direction);

        if(abs(bullets[i].x) > settings.screen_right ||
           abs(bullets[i].y) > settings.screen_top){
            bullets.erase(bullets.begin() + i);
           }
    }
}

Game::~Game()
{
    //dtor
}

