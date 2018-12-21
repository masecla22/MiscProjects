#pragma once
#include "methods.h"
#include "velocity.h"
#include "point.h"
class ball {
  public:
    point pos = point(0,0);
    velocity vel;
    void draw() {
        ellipse(pos.x,pos.y,0,0,constants::BALL_RADIUS,constants::BALL_RADIUS);
    }
    ball(point pos1,velocity vel1)
    {
        pos=pos1;
        vel=vel1;
    }
    void move() {
        pos.x+=vel.x;
        pos.y+=vel.y;
        if(pos.x>constants::SCREEN_WIDTH||pos.x<0) {
            runSound();
            vel.x*=-1;
        }
        if(pos.y>constants::SCREEN_HEIGHT||pos.y<0) {
            runSound();
            vel.y*=-1;
        }

    }

};
