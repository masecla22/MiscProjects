#pragma once
#include <thread>
#include <vector>
#include "globals.h"
#include "collision.h"


void createWindow(){
    initwindow(constants::SCREEN_WIDTH,constants::SCREEN_HEIGHT,"lmao what",100,100);
}

void createSound()
{
    Beep(constants::SOUND_FREQUENCY,constants::SOUND_LENGTH);
}
void runSound(){
    std::thread t1(createSound);
    t1.detach();
}
double getDistance(point a,point b){
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
std::vector<collision> getCollision(){
    std::vector<collision> result;
    for(ball a : globals::balls)
        for(ball b: globals::balls)
            if(getDistance(a.pos,b.pos)<=constants::BALL_RADIUS)
                result.push_back(collision(a,b));
    return result;
}
