#ifndef GAME_MANAGEMENT_H_
#define GAME_MANAGEMENT_H_

#include "Common.h"
#include "base.h"
#include "Mainobj.h"
#include "Threat.h"
#include "Explosion.h"
#include "Gift.h"
#include "Text.h"
#include "Boss.h"

class game_management{
public:

    game_management();
    ~game_management();

    void init(std::string title);
    void handle_event();
    void handle_boss();
    void handle_Threat();
    void handle_game();
    void clean();
    void menu(const std::string& item);
    void reset_game();

    bool get_running() { return isRunning; }
    bool check_collision(const SDL_Rect& object1,const SDL_Rect& object2);
    bool check_mouse_vs_item(const int& x,const int& y,const SDL_Rect& rect);

private:

	SDL_Event gEvent;
    SDL_Window* gWindow;
    SDL_Renderer* gRenderer;


	Mix_Music* g_music_start;
    Mix_Chunk* g_sound_level_up;
	Mix_Chunk* g_sound_exp[3];
    Mix_Chunk* g_sound_bullet[3];
    Mix_Chunk* g_sound_Threat_hit[3];
    

    TTF_Font* g_font_text;
    TTF_Font* g_font_menu;
    TTF_Font* g_font_end_game;

	Gift gift;
	Boss boss;
	Mainobj mainobj;

	base support;
    base background;

    Explosion exp;
    Explosion exp_boss;

    Text hint;
    Text end_game;
	Text kill_text;
    Text heart_text;
    Text lighting_text;
    
    int kill;
	int menu_number;
	int bullet_level;
    int time_end_game;
    int count_num_exp;

	bool isRunning;
	double scrolling;

    std::vector<Threat*> p_Threat_list;

};
#endif