#include <iostream>
#include <windows.h>
#include <graphics.h>
#include <conio.h>
#include <bits/stdc++.h>

using namespace std;
struct car
{
    int xPos=0;
    int drawCar()
    {
        int yconst=350;
        ellipse(xPos,yconst,360,360,20,20);
        ellipse(xPos+120,yconst,360,360,20,20);
        rectangle(xPos-15,yconst-60,xPos+130,yconst-20);
    }
};
int main()
{
    initwindow(900,600,"TEST",150,150);
    car theCar;
    float velocity=3;
    theCar.drawCar();
    int maxVel=500;
    ///I will do this just to have fun :D
    while(true)
    {
        if(GetAsyncKeyState(VK_RIGHT)!=0)
        {
            cleardevice();
            if(theCar.xPos<=900-velocity)
              theCar.xPos+=int(velocity);
            theCar.drawCar();
                cout<<theCar.xPos<<endl;
        }
        if(GetAsyncKeyState(VK_LEFT)!=0)
        {
            cleardevice();
            if(theCar.xPos>=velocity)
            theCar.xPos-=int(velocity);
            theCar.drawCar();
            cout<<theCar.xPos<<endl;
        }
        if(GetAsyncKeyState(VK_UP)!=0)
        {
            cout<<velocity<<"/"<<maxVel<<endl;
            if(velocity+0.2<maxVel)
            velocity+=0.2;
        }
        if(GetAsyncKeyState(VK_DOWN))
        {
            cout<<velocity<<"/"<<maxVel<<endl;
            if(velocity>0)
            velocity-=0.2;
        }
        Sleep(5);
    }
    getch();
    closegraph();
    return 0;
}
