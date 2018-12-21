#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <windows.h>
#include <winuser.h>

using namespace std;
struct player1{
int score=0;
int yPos=190;
void drawMe(){
    setcolor(WHITE);
    setfillstyle(SOLID_FILL,WHITE);
    floodfill(24,yPos-97,WHITE);
    rectangle(20,yPos-100,70,yPos+100);
}
};
struct player2{
int score=0;
int yPos=0;
};
struct ball {
int xPos=0;
int yPos=0;
};
int main()
{
    initwindow(900,600,"PONG",100,100);
    player1 a1;
    a1.drawMe();
    while (true)
    {
        if(GetAsyncKeyState(0x57)!=0 && a1.yPos>120)
        {
            a1.yPos-=5;
            cleardevice();
            a1.drawMe();
        }
        if(GetAsyncKeyState(0x53)!=0&&a1.yPos<480)
        {
            a1.yPos+=5;
            cleardevice();
            a1.drawMe();
        }

    }
    getch();
    closegraph();
    return 0;
}
