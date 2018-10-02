#ifndef GAME_H
#define GAME_H

#include <windows.h>
#include <GL/glut.h>
#include "Settings.h"
#include "Tank.h"
#include "Bullet.h"
#include <vector>

class Game
{
    public:
        Game();
        void updateScreen(Tank *, std::vector <Bullet>&);
        void keyReleaseGame(unsigned char, Tank *);
        void keyPressGame(unsigned char, Tank *);
        void checkEventsGame(Tank *, std::vector<Bullet>&, Settings);
        void checkEventsTank(Tank *, std::vector<Bullet>&, Settings);
        void checkEventsBullet(std::vector<Bullet>&, Settings);
        virtual ~Game();


    protected:

    private:
};

#endif // GAME_H
