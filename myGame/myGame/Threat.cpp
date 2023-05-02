#include "stdafx.h"
#include "Threat.h"

Threat::Threat(){
    rect_.x = SCREEN_WIDTH;
    rect_.y = SCREEN_HEIGHT / 2;
    x_val_ = 0;
    y_val_ = 0;
    status_.turn_down = 0;
    status_.turn_up = 0;
    status_.turn_left = 0;
    status_.turn_right = 1;
    frame_ =0;
    heart_ = 0;
    come_back_ = true;
}

Threat::~Threat(){

}

SDL_Rect Threat::GetRectFrame(){
    SDL_Rect rect;
    rect.x = rect_.x;
    rect.y = rect_.y;
    rect.w = WIDTH_THREAT;
    rect.h = HEIGHT_THREAT;
    return rect;
}
 

void Threat::set_clips(){
        for(int i=0; i < 18; i++){
            clip_[i].x = i * WIDTH_THREAT;
            clip_[i].y = 0;
            clip_[i].w = WIDTH_THREAT;
            clip_[i].h = HEIGHT_THREAT;
        }
}


void Threat::Show(SDL_Renderer* screen){
    if(come_back_ == true){
        frame_++;
        if(frame_/5 >= 18){
            frame_ = 0;
        }
        SDL_Rect renderQuad = {rect_.x,rect_.y,WIDTH_THREAT,HEIGHT_THREAT};
        SDL_RenderCopy(screen,object_,&clip_[frame_/5],&renderQuad);
    }
}


void Threat::HandleBullet(SDL_Renderer* screen){

        for(int i=0 ; i < (int)bullet_list_.size(); i++){
            bullet* p_bullet = bullet_list_.at(i);
            if(p_bullet){
                if(p_bullet->get_is_move()){
                    p_bullet->Render(screen);
                    p_bullet->HandleMoveThreatBullet();
                }
                else{
                    p_bullet->SetRect(this->rect_.x + WIDTH_THREAT / 2 - p_bullet->GetRect().w / 2,this->rect_.y + HEIGHT_THREAT);
                    p_bullet->set_is_move(true);
                }
            }
        }
}


void Threat::InitBullet(bullet* p_bullet,SDL_Renderer* screen){
    if(p_bullet != NULL){
        if(p_bullet->loadImg("image//bullet.png",screen)){
            p_bullet->set_is_move(true);
            p_bullet->SetRect(this->rect_.x + WIDTH_THREAT / 2 - p_bullet->GetRect().w / 2,this->rect_.y + HEIGHT_THREAT);
            p_bullet->set_y_val(THREAT_BULLET_SPEED);
            bullet_list_.push_back(p_bullet);
        }
    }
}


void Threat::Move(){
    if(come_back_==true){
        rect_.y += y_val_;
        if(status_.turn_left){
            rect_.x -= x_val_;
        }
        if(status_.turn_right){
            rect_.x += x_val_;
        }
        if(status_.turn_up){
            rect_.y -= 2 * y_val_;
        }
		if(rect_.y > SCREEN_HEIGHT ){
			status_.turn_up = 1;
			status_.turn_down = 0;
		}
        else if(rect_.y + HEIGHT_THREAT < 0){
            status_.turn_down = 1;
            status_.turn_up = 0;
        }
        if(rect_.x <= - WIDTH_THREAT*3){
            status_.turn_right = 1;
            status_.turn_left = 0;
        }
        else if(rect_.x >= SCREEN_WIDTH + 3*WIDTH_THREAT){
            status_.turn_left = 1;
            status_.turn_right = 0;
        }
    }
}


void Threat::RemoveBullet(const int& idx){
    for(int i=0; i < (int)bullet_list_.size() ; i++){
        if(idx < (int)bullet_list_.size()){
            bullet* p_bullet = bullet_list_.at(idx);
            bullet_list_.erase(bullet_list_.begin() + idx);

            if(p_bullet != NULL){
                delete p_bullet;
                p_bullet = NULL;
            }
        }
    }
}


void Threat::set_status_right(){
    status_.turn_down = 0;
    status_.turn_up = 0;
    status_.turn_left = 0;
    status_.turn_right = 1;
}