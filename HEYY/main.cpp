#include <iostream>
#include <graphics.h>
#include <string>
#include <conio.h>

#define UP 1
#define LEFT 2
#define DOWN 3
#define RIGHT 4

using namespace std;

int lineLn = 20;
int transX = 160;
int transY = 700;

void rotates(int &direction,int rotation){
    if(rotation == RIGHT){
        if(direction==UP){
            direction = RIGHT;
            return ;
        }
        direction --;
    }
    else if(rotation == LEFT){
        if(direction==RIGHT) {
            direction = UP;
            return;
        }
        direction++;
    }
}

struct Point {
    int x,y;
    Point(int ix,int iy)
    {
        x = ix;
        y = iy;
    }
};

void apply(Point &p,int direction){
    if(direction==UP)
        p.y--;
    if(direction==DOWN)
        p.y++;
    if(direction==LEFT)
        p.x--;
    if(direction==RIGHT)
        p.x++;
}

void lines(Point a,Point b){
    line(a.x*lineLn+transX,a.y*lineLn+transY,b.x*lineLn+transX,b.y*lineLn+transY);
}

Point currentPos(0,0);
int rotation = RIGHT;
void runProgram(std::string program)
{
    for(int i=0;i<program.size();i++)
    {
        if(program[i]=='F'){
            Point p = currentPos;
            apply(currentPos,rotation);
            lines(p,currentPos);
        }if(program[i]=='R')
            rotates(rotation,RIGHT);
        if(program[i]=='L')
            rotates(rotation,LEFT);
    }
}

std::string nextProgram(std::string program)
{
    return program+"R"+program+"L";
}
std::string prg(int n) {
    if(n==0)
        return "F";
    return prg(n-1)+"R"+prg(n-1)+"L";
}

int main()
{
    //initwindow(900,950,"Robotel",100,0);
    //for(int i=0;i<950;i++)
    //    line(0,i,900,i);
    //setcolor(0);
    cout<<prg(1)<<endl;
    cout<<prg(1).size()<<endl;
    //runProgram(prg(8));
    //cout<<currentPos.x<<" "<<currentPos.y<<endl;
    //_getch();
    return 0;
}
