

// Heros_Game_SDL2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "game_management.h"

int main(int argc,char* argv[]){
    game_management WATER_HERO;
    WATER_HERO.init("DATmieu2K4");
    WATER_HERO.menu("Play");

    while(WATER_HERO.get_running()){
        WATER_HERO.handle_event();
        WATER_HERO.handle_game();
    }

    WATER_HERO.clean();
    return 0;
}
 


