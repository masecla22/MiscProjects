#include <iostream>
#include <windows.h>
#include <graphics.h>

using namespace std;

enum CARDINAL {
    NORTH, SOUTH, EAST, WEST
};

int drawcube(int x,int y,int color)
{
    //setcolor(1);
    rectangle(x*25,y*25,x*25+25,y*25+25);
    setfillstyle(SOLID_FILL,color);
    floodfill(x*25+23,y*25+23,WHITE);
    rectangle(x*25-1,y*25-1,x*25+26,y*25+26);
}
int main()
{
    cout<<CARDINAL::NORTH;
    return 0;
}
