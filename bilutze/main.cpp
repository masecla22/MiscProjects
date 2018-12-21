#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <mattcore.h>
#include <windows.h>

#include "ball.h"
#include "ballMethods.h"
#include "methods.h"

using namespace std;
using namespace matt::core;

int main()
{
    createWindow();
    //for(int i = 0;i<50;i++){globals::balls.push_back(ball(point(random(0,100),random(0,100)),velocity(random(0,5),random(0,5))));}
    globals::balls.push_back(ball(point(0,300),velocity(5,0)));
    globals::balls.push_back(ball(point(900,300),velocity(-5,0)));
    while(2){
        thread t2(drawBalls);
        thread t1(nextStep);
        t1.detach();
        t2.detach();
        Sleep(10);
        cleardevice();
        printf("Size: %d",getCollision().size());
    }
    _getch();

    return 0;
}
