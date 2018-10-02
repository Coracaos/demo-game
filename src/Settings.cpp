#include "Settings.h"

Settings::Settings()
{
    game_title = "War Tank";


    screen_right = 340.0f;
    screen_left = -340.0f;
    screen_top = 340.0f;
    screen_bottom = -340.0f;
    screen_width = screen_right - screen_left;
    screen_height = screen_top - screen_bottom;
    screen_x = 25.0f;
    screen_y = 25.0f;

    tank_width = 40.f;
    tank_height = tank_width;
    tank_x = 0.0f;
    tank_y = 0.0f;
    tank_rot = 0.0f;
    tank_speed = 4.0f;

    bullet_radius = 4.0f;
    bullet_speed = 8.0f;
}

Settings::~Settings()
{
    //dtor
}

