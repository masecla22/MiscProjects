#pragma once
#include <cmath>
#include "globals.h"

void drawBalls(){
    for(auto& f : globals::balls)
        f.draw();
}
void nextStep(){
    for(auto& f : globals::balls)
        f.move();
}
