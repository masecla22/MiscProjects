#include <iostream>
#include <graphics.h>
#include <vector>
#include <cmath>
#include <random>
#include <windows.h>
#include <conio.h>
#include <ctime>
#include <limits>

#define WIDTH 900
#define HEIGHT 600
#define GLOBAL_TRAIL false
#define TRAIL_ACCURACY 30

double randomDouble(double const fMin, double const fMax)
{
  double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}


class Point {
public:
    double x,y;
    Point(double ix,double iy) {
        x = ix;
        y = iy;
    }
    Point(){}
    double distanceTo(Point p) {
        double dx = x-p.x,dy = y-p.y;
        return sqrt(dx*dx+dy*dy);
    }
    double distanceSquared(Point p) {
        double dx = x-p.x,dy = y-p.y;
        return dx*dx+dy*dy;
    }
    Point middleTo(Point p) {
        return Point((x+p.x)/2.0,(y+p.y)/2.0);
    }
    Point multiplyWith(double coeff) {
        return Point(x*coeff,y*coeff);
    }
    Point divideWith(double coeff) {
        return Point(x/coeff,y/coeff);
    }
    Point addWith(Point p) {
        return Point(x+p.x,y+p.y);
    }
    bool equals(Point p)
    {
        return x==p.x&&y==p.y;
    }
};

class Ball {
public:
    Point position, velocity;
    std::vector<Point> trail;
    double mass, radius;
    int cr=0;
    Ball(Point iposition,Point ivelocity,double iradius,double imass){
        position = iposition;
        velocity = ivelocity;
        radius = iradius;
        mass = imass;
    }
    Ball(){
        double speed = 10;
        position = Point(randomDouble(0,WIDTH),randomDouble(0,HEIGHT));
        velocity = Point(randomDouble(-speed,speed),randomDouble(-speed,speed));
        radius = /*randomDouble(10,30)*/ 20;
        mass = /* randomDouble(2,50) */ 5;
    }

    void collideWith(Ball &target) {
        Point v1 = velocity;
        Point v2 = target.velocity;
        Point v1f = (v1.multiplyWith(mass).addWith(v2.multiplyWith(target.mass))).multiplyWith(2).divideWith(mass+target.mass).addWith(velocity.multiplyWith(-1.0));
        Point v2f = (v1.multiplyWith(mass).addWith(v2.multiplyWith(target.mass))).multiplyWith(2).divideWith(mass+target.mass).addWith(target.velocity.multiplyWith(-1.0));
        velocity = v1f;
        target.velocity = v2f;
    }

    bool shouldCollideWith(Ball target) {
        if(position.equals(target.position))
            return false;
        double sumRad = radius+target.radius;
        return sumRad*sumRad>position.distanceSquared(target.position);
    }

    void applyStep(){
        cr++;
        position = position.addWith(velocity);
        if(position.x<0 || position.x>WIDTH)
            velocity.x*=-1;
        if(position.y<0 || position.y>HEIGHT)
            velocity.y*=-1;

        if(GLOBAL_TRAIL && cr%TRAIL_ACCURACY==0){
            std::cout<<"SIZE: "<<trail.size()<<std::endl;
            trail.push_back(position);
        }
    }

    void render(){
        circle(position.x,position.y,radius);
        if(GLOBAL_TRAIL){
            for(int i=0;i<trail.size()-1;i++)
            {
                if(trail.size()<2)
                    break;
                Point p1=trail[i],p2=trail[i+1];
                line(p1.x,p1.y,p2.x,p2.y);
            }
        }
    }
};


int main() {
    initwindow(WIDTH,HEIGHT,"Testing balls",100,100);

    std::vector<Ball> balls;
    srand(time(NULL));

    for(int i=0;i<5;i++)
    {
        balls.push_back(Ball());
    }

    while(true){
        for(Ball &b : balls){
            b.render();
            b.applyStep();
            for(Ball &c:balls){
                if(b.shouldCollideWith(c))
                    b.collideWith(c);
            }
        }

        Sleep(10);
        cleardevice();
    }


    _getch();
    return 0;
}
