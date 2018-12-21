#include <iostream>
#include <graphics.h>
#include <cstring>

using namespace std;
class point{
public:
    double x,y;
    point(double x1,double y1)
    {
        x=x1;
        y=y1;
    }
    moveX(double toAdd)
    {
        x+=toAdd;
    }
    moveY(double toAdd)
    {
        y+=toAdd;
    }
};
void dLine(point a,point b)
{
    line(a.x,a.y,b.x,b.y);
}
bool isOp(char a)
{
    if(a=='+'||a=='-')
        return 1;
    return 0;
}
point prolLine(point p1,point p2,int perc)
{
    point m((p1.x*perc+p2.x*(100-perc))/100,(p1.y*perc+p2.y*(100-perc))/100);
    return m;
}
void remChar(char a[255],const int position)
{
    int h=strlen(a);
    for(int i=position;i<strlen(a);i++)
        a[i]=a[i+1];
    a[h-1]=0;
}
void remSpac(char a[255]){
    for(int i=0;i<strlen(a);i++)
        if(a[i]==' ')
            remChar(a,i);
}
point getPoint(point a,int multi)
{
    a.x*=multi;
    a.y*=multi;
    a.y = (300-a.y);
    a.x = (450+a.x);
    point f(a.x,a.y);
    return f;
}
void drawGraph(point p1,point p2,int multi)
{
    p1=getPoint(p1,multi);p2=getPoint(p2,multi);
    dLine(p1,prolLine(p1,p2,15000));
    dLine(p1,prolLine(p1,p2,-15000));
}
int main()
{
    ///32x+5
    char a[255],firstPart[255],secondPart[255],oper;
    cout<<"f(x)=";
    cin.getline(a,255);
    initwindow(900,600,"Grapher",100,100);
    line(450,0,450,600);
    line(0,300,900,300);
    ellipse(440,310,0,0,5,5);
    remSpac(a);
    int i=0;
    while(isOp(a[i])==0){
        firstPart[i]=a[i];
        i++;
    }
    firstPart[i]=0;
    i=strlen(firstPart);
    while(i<strlen(a))
    {
        secondPart[(i-strlen(firstPart))]=a[i];
        i++;
    }
    secondPart[i-strlen(firstPart)]=0;
    double coef1,coef2;
    coef1=atoi(firstPart);
    coef2=atoi(secondPart);
    /**
        f(x)=3x+5
        a = 3 b = 5
        x = 0 -> y = b
        y = 0 ->x = (-b)/a
    */
    point p1(0,coef2),p2((0-coef2)/coef1,0);
    drawGraph(p1,p2,20);
    outtextxy(20,20,"Nice");
    getch();
    return 0;
}
