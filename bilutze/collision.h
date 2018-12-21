#include "ball.h"

class collision
{
public:
    ball a,b;
    void applyCollision(){
        ball c = a;
        a.vel = a.vel.add(b.vel);
        b.vel = b.vel.add(c.vel);
    }
    collision(ball a1,ball b1)
    {
        a = a1;
        b = b1;
    }
};
