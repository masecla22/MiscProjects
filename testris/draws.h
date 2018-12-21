#include <iostream>
#include <graphics.h>
#include <winuser.h>
#include <conio.h>
#define UP 1
#define LEFT 2
#define RIGHT 3
#define DOWN 4
using namespace std;
int getInput()
{
    int drect;
    if(GetAsyncKeyState(VK_UP)!=0 && drect!=DOWN)
        drect=UP;
    if(GetAsyncKeyState(VK_DOWN)!=0&& drect!=UP)
        drect=DOWN;
    if(GetAsyncKeyState(VK_LEFT)!=0&& drect!=RIGHT)
        drect=LEFT;
    if(GetAsyncKeyState(VK_RIGHT)!=0&& drect!=LEFT)
        drect=RIGHT;
    if(drect<10)
    return drect;
    return 0;
}
