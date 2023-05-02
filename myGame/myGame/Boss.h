#ifndef BOSS_H_
#define BOSS_H_

#include <vector>
#include "common.h"
#include "base.h"
#include "bullet.h"
#include "Explosion.h"


#define WIDTH_BOSS 200
#define HEIGHT_BOSS 117
#define BOSS_SPEED 1
#define BOSS_BULLET_SPEED 8

class Boss : public base{
public:
    Boss();
    ~Boss();

    void set_x_val(const int& Xval) { x_val_ = Xval; }
    void set_y_val(const int& Yval) { y_val_ = Yval; }
    int get_x_val()const { return x_val_; }
    int get_y_val()const { return y_val_; }

    void Move();
    void Show(SDL_Renderer* screen);
    void set_clips();
    SDL_Rect GetRectFrame();

    void set_bullet_list(std::vector<bullet*> bullet_list) { bullet_list_ = bullet_list; }
    std::vector<bullet*> get_bullet_list() { return bullet_list_; }

    void InitBullet(bullet* p_bullet,SDL_Renderer* screen);
    void MakeBullet(SDL_Renderer* screen);

    void set_heart(const double& Heart) { heart_ = Heart; }
    float get_heart()const { return heart_; }
    void Decrease(const double& bullet_damage) { heart_ -= bullet_damage; }
    void show_heart_boss(SDL_Renderer* screen,int x,int y,int w,int h);

private:
    double heart_;

    int x_val_;
    int y_val_;
	int frame_;

	std::vector<bullet*> bullet_list_;
    StatusTHREAT status_;
    SDL_Rect clip_[10];
};



#endif