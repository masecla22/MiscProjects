#include <iostream>
#include <graphics.h>
#include <cmath>
#include <ctime>
using namespace std;
int main()
{
    initwindow(900,600,"TEST",100,100);
    for(int i=0;i<9000;i++)
    {
    setcolor(RGB(i*i,int(cos(i)*287)%255,i*time(NULL)%255));
    ellipse(450/sin(i*i),300*sin(i),359,i,190-i*sin(i)*sin(100),190-cos(i*i)+i*tan(i*i*i));
    ellipse(450*sin(i*i),300/sin(i),359,i,190-i*sin(i)*sin(100),190-cos(i*i)+i*tan(i*i*i));
    Sleep(1);
    if(i%500==0)
        cleardevice();
    //cout<<"Eh"<<endl;
    }
    getch();
    return 0;
}
