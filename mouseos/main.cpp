#include <bits/stdc++.h>
#include <windows.h>
#include "mattcore.h"

using namespace std;
int GetXCoord()
{
    POINT pt;
    GetCursorPos(&pt);
    int x=pt.x;
    return x;
}
int GetYCoord()
{
    POINT pt;
    GetCursorPos(&pt);
    int y=pt.y;
    return y;
}
int drawpix(int x,int y)
{
    for(int i=0;i<x;i++)
        cout<<"  ";
    clear();
}
int main()
{
    int posX=0,posY=0;
    int devX=0,devY=0;
    while(2)
    {
        int x=GetXCoord(),y=GetYCoord();
        Sleep(1);
            devX=x-GetXCoord();
            devY=y-GetYCoord();
        if(devX>0)
            posX++;
        if(devY>0)
            posY++;
        if(devX<0)
            posX--;
        if(devY<0)
            posY--;
        if(devX!=0 || devY!=0)
            SetCursorPos(200,200);
        clear();
        cout<<posX<<" "<<posY<<"   "<<endl;
    }
    return 0;
}
