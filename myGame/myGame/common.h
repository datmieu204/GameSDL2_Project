#ifndef COMMON_H_
#define COMMON_H_

#include <vector>
#include <string>
#include <SDL.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <SDL_image.h>

const int BACKGROUND_WIDTH = 1200;
const int BACKGROUND_HEIGHT = 4800;
const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 760;
const double SCREEN_SPEED = 0.4;

const int COLOR_KEY_R = 170;
const int COLOR_KEY_G = 170;
const int COLOR_KEY_B = 170;
const int RENDER_DRAW_COLOR = 255;

const int NUMBER_OF_EXP = 3;
const int NUMBER_OF_THREAT = 36;
const int NUMBER_OF_THREATS_PER_ROW = 12;

const int ONE_TURN_GIFT = 14;
const int BOSS_HEART = 333;
const int THREAT_HEART = 3;
const int DISTANCE_BETWEEN_THREATS = 100;

const int TYPE_1 = 0;
const int TYPE_2 = 1;
const int TYPE_3 = 2;

const int LEVEL_UP = 3;
const double BULLET_DAMAGE_LEVEL_UP = 0.5;

struct StatusTHREAT{
    int turn_left;
    int turn_right;
    int turn_up;
    int turn_down;
};

#endif