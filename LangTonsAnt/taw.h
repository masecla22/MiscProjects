#include <iostream>
#include <graphics.h>
#include <conio.h>
#include <mattcore.h>
#include <vector>
#define UP 0
#define RIGHT 1
#define DOWN 2
#define LEFT 3

int sizes=10;
float pixelSize = 1000/sizes;
std::string behaviour = "RRRRRRRRL";
int howManyColors = behaviour.size();
class board
{
public:
    std::vector<std::vector<unsigned int>  > cells;
    board()
    {
        for(int i=0; i<=sizes+1; i++)
        {
            std::vector<unsigned int> toPush;
            for(int j=0; j<=sizes+1; j++)
                toPush.push_back(0);
            cells.push_back(toPush);
        }
    }
};
void turnLeft(int &dir)
{
    dir--;
    if(dir==-1)
        dir=LEFT;
}
void turnRight(int &dir)
{
    dir++;
    if(dir==4)
        dir=UP;
}
class point
{
public:
    int x=sizes/2,y=x;
};
void drawPixel(const int &x,const int &y,int color)
{
    if(pixelSize!=1){
        setcolor(color);
        for(int i=0; i<=pixelSize; i++)
            line(x*pixelSize,y*pixelSize+i,x*pixelSize+pixelSize,y*pixelSize+i);
    }
    else
        putpixel(x,y,color);
}
void nextStep(point &pos,const int &direction)
{
    if(direction==UP)
    {
        if(pos.y<1)
            pos.y=sizes-1;
        else
            pos.y--;
    }
    else if(direction==DOWN)
    {
        if(pos.y>sizes-1)
            pos.y=0;
        else
            pos.y++;
    }
    else if(direction==LEFT)
    {
        if(pos.x<1)
            pos.x=sizes-1;
        else
            pos.x--;
    }
    else if(direction==RIGHT)
    {
        if(pos.x>sizes-1)
            pos.x=0;
        else
            pos.x++;
    }
}
class ant
{
public:
    point position;
    int direction=UP;
    void nextRun(board &theGame)
    {
        theGame.cells[position.y][position.x]++;
        if(theGame.cells[position.y][position.x]==behaviour.size())
            theGame.cells[position.y][position.x]=0;
        drawPixel(position.x,position.y,theGame.cells[position.y][position.x]);
        if(behaviour.at(theGame.cells[position.y][position.x])=='L')
            turnLeft(direction);
        else
            turnRight(direction);
        nextStep(position,direction);
    }
};
