#ifndef THREAT_H_
#define THREAT_H_

#include <vector>
#include "common.h"
#include "base.h"
#include "bullet.h"
#include "Explosion.h"


#define WIDTH_THREAT 75
#define HEIGHT_THREAT 68
#define THREAT_SPEED 1
#define THREAT_BULLET_SPEED 2

class Threat : public base{
public:
    Threat();
    ~Threat();

    void set_x_val(const int& Xval){x_val_ = Xval;}
    void set_y_val(const int& Yval){y_val_ = Yval;}
    int get_x_val()const{return x_val_;}
    int get_y_val()const{return y_val_;}

    void Move();
    void Show(SDL_Renderer* screen);
    void set_clips();
    SDL_Rect GetRectFrame();

    void set_bullet_list(std::vector<bullet*> bullet_list) { bullet_list_ = bullet_list; }
    std::vector<bullet*> get_bullet_list() { return bullet_list_; }
    void InitBullet(bullet* p_bullet,SDL_Renderer* screen);
    void HandleBullet(SDL_Renderer* screen);
    void RemoveBullet(const int& idx);

    void set_heart(const double& Heart) { heart_ = Heart; }
    float get_heart()const { return heart_; }
    void Decrease(const double& bullet_damage) { heart_ -= bullet_damage; }

    void set_come_back(const bool& comeback) { come_back_ = comeback; }
    bool get_come_back()const { return come_back_; }
    void set_status_right();

private:
    double heart_;

    int x_val_;
    int y_val_;

	int frame_;
	bool come_back_;

	std::vector<bullet*> bullet_list_;
    StatusTHREAT status_;
    SDL_Rect clip_[18];
};



#endif