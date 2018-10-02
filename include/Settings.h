#ifndef SETTINGS_H
#define SETTINGS_H

#include <string>

class Settings
{
    public:
        // Screen
        std::string game_title;
        float screen_width;
        float screen_height;
        float screen_right;
        float screen_left;
        float screen_top;
        float screen_bottom;
        int screen_x;
        int screen_y;

        // Tank
        float tank_width;
        float tank_height;
        float tank_x;
        float tank_y;
        float tank_rot;
        float tank_speed;

        //bullet
        float bullet_radius;
        float bullet_speed;

        Settings();

        virtual ~Settings();

    protected:

    private:
};

#endif // SETTINGS_H
