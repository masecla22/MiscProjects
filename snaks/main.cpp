#include <iostream>
#include <graphics.h>
#include <vector>
#define UP 1
#define DOWN 2
#define RIGHT 3
#define LEFT 4

using namespace std;
class point
{
public:
    int x,y;
    point(int x1,int y1)
    {
        x=x1;
        y=y1;
    }
};
void vectPop(vector<point> a,point toAdd)
{
    for(int i=0; i<int(a.size())-1; i++)
        a[i]=a[i+1];
    a[a.size()-1]=toAdd;
}
class snake
{
public:
    vector<point> positions;
    snake(vector<point> positions1)
    {
        for(int i=0; i<int(positions1.size()); i++)
            positions.push_back(positions1.at(i));
    }
    void nextStep(int direction)
    {
        if(direction==UP)
        {
            point f = positions.at(positions.size()-1);
            f.y--;
            if(f.y<3)
                f.y=30;
            vectPop(positions,f);
        }
        if(direction==DOWN)
        {
            point f = positions.at(positions.size()-1);
            f.y++;
            if(f.y>30)
                f.y=3;
            vectPop(positions,f);
        }
        if(direction==RIGHT)
        {
            point f = positions.at(positions.size()-1);
            f.x++;
            if(f.x>45)
                f.x=0;
            vectPop(positions,f);
        }
        if(direction==LEFT)
        {
            point f = positions.at(positions.size()-1);
            f.x--;
            if(f.x<0)
                f.x=45;
            vectPop(positions,f);
        }
    }
    void draw(){
        for(int i=0;i<positions.size();i++)
            rectangle(positions.at(i).x*20,positions.at(i).y*20,20,20);
    }
};
class food
{
public:
    point position;

};
int main()
{
    initwindow(900,600,"Snake game -by Quintickle",100,100);
    int dir=DOWN;
    vector<point> a;
    point f(1,1),s(1,2);
    a.push_back(f);
    a.push_back(f);
    a.push_back(s);
    a.push_back(f);
    snake player(a);
    player.draw();
    while(true)
    {
        cout<<"a";
        if(GetAsyncKeyState(VK_DOWN)!=0)
            dir=DOWN;
        if(GetAsyncKeyState(VK_UP)!=0)
            dir=UP;
        if(GetAsyncKeyState(VK_LEFT)!=0)
            dir=LEFT;
        if(GetAsyncKeyState(VK_RIGHT)!=0)
            dir=RIGHT;
        player.nextStep(dir);
        Sleep(200);
        cleardevice();


    }

    getch();

    return 0;
}
