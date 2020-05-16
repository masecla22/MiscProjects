#include <graphics.h>
#include <conio.h>
#include "mattcore.h"
#include <math.h>
#define WIDTH 900
#define HEIGHT 600
#define PI 3.141592653589793238462643383
const int hitBoxOn =0;
const int trailLenght = 1;
const int howManys=10;
const int maxVel = 10;
const int deviation = 6;
const int breadCrumbPrec=4;
const int breadcrumbLenght=40;
const int breadcrumbActive=0;
const int activateCollision=1;
const int showCircle =1;
struct points {
    int x,y;
};
struct rect {
    bool fromCenter=1;
    int x,y,width,height;
    void draw() {
        if(fromCenter==0) {
            line(x,y,x+width,y);
            line(x+width,y,x+width,y+height);
            line(x+width,y+height,x,y+height);
            line(x,y,x,y+height);
        } else {
            line(x-width/2,y-height/2,x+width/2,y-height/2);
            line(x-width/2,y-height/2,x-width/2,y+height/2);
            line(x-width/2,y+height/2,x+width/2,y+height/2);
            line(x+width/2,y+height/2,x+width/2,y-height/2);
        }
    } points getl() {
        points f;
        f.x = x-width/2;
        f.y = y-height/2;
        return f;
    } points getr() {
        points f;
        f.x = x+width/2;
        f.y = y+height/2;
        return f;
    }
};
int pushArray(points a[200],int xPos,int yPos,int lenght) {
    for(int i=0; i<lenght-1; i++)
        a[i]=a[i+1];
    a[lenght-1].x=xPos;
    a[lenght-1].y=yPos;
}
int doOverlap(rect a,rect b) {
    return(a.getl().x<b.getr().x&&a.getr().x>b.getl().x&&a.getl().y<b.getr().y&&a.getr().y>b.getl().y);
}
points genPoint(int xPos,int yPos) {
    points f;
    f.x=xPos;
    f.y=yPos;
    return f;
}
struct ball {
    int xPos,yPos,xVel,yVel,whatPos;
    rect hitBox;
    points breadcrumbs[200];
    void construct(int xPoss,int yPoss,int xVell, int yVell) {
        xPos = xPoss;
        yPos = yPoss;
        xVel = xVell;
        yVel = yVell;
        hitBox.x=xPos;
        hitBox.y=yPos;
        hitBox.width=40;
        hitBox.height=40;
        whatPos=0;
    }
    int update (int whatUpdate) {
        xPos+=xVel;
        yPos+=yVel;
        hitBox.x=xPos;
        hitBox.y=yPos;
        if(xPos>=WIDTH || xPos<=0)
            xVel*=-1;
        if(yPos>=HEIGHT || yPos<=0)
            yVel*=-1;
        if(whatUpdate%breadCrumbPrec==0&& breadcrumbActive)
            if(whatPos<breadcrumbLenght)
                breadcrumbs[whatPos++]=genPoint(xPos,yPos);
            else
                pushArray(breadcrumbs,xPos,yPos,whatPos);
    }
    points getr() {
        points f;
        f.x = xPos-20/2;
        f.y = yPos-20/2;
        return f;
    } points get1() {
        points f;
        f.x = xPos+20/2;
        f.y = yPos+20/2;
        return f;
    } int draws () {
        if(hitBoxOn==1)
            hitBox.draw();
        if(showCircle==1)
            ellipse(xPos,yPos,0,0,20,20);
        if(breadcrumbActive==1)
            for(int i=0; i<whatPos-1; i++)
                line(breadcrumbs[i].x,breadcrumbs[i].y,breadcrumbs[i+1].x,breadcrumbs[i+1].y);
    }
    void reverses() {

        xVel*=-1;
        yVel*=-1;
    }
};
int checkColl(ball the[200],int which,int howMany) {
    for(int i=0; i<howMany; i++)
        if(i!=which)
            if(doOverlap(the[which].hitBox,the[i].hitBox)!=0)
                return i;
    return -1;
}
void updateBalls(ball the[200],int howMany,int which) {
    for(int i=0; i<howMany; i++) {
        the[i].update(which);
        if(activateCollision==1) {
            int a = checkColl(the,i,howMany);
            int contor=0;
            if(a!=-1 && a!=i) {
                the[i].reverses();
                the[a].reverses();
                while(doOverlap(the[i].hitBox,the[a].hitBox)==1&&contor<50) {
                    the[i].xPos++;
                    the[a].xPos--;
                    the[a].hitBox.x--;
                    the[i].hitBox.x++;
                    contor++;
                }
            }
        }
    }
}
void drawBalls(ball the[200],int howMany) {
    for(int i=0; i<howMany; i++)
        the[i].draws();
}
int main() {
    int i=0;
    ball theBall[200];
    initwindow(WIDTH,HEIGHT,"test",200,200);
    getch();
    for(int i=0; i<howManys; i++) {
        theBall[i].construct(random(1,WIDTH),random(1,HEIGHT),random(1,maxVel),random(1,maxVel));
    }
    int sleepVar=15;
    while(true) {
        updateBalls(theBall,howManys,i);
        drawBalls(theBall,howManys);
        Sleep(sleepVar);
        if(i%trailLenght==0)
            cleardevice();
        i++;
        if(GetAsyncKeyState(VK_DOWN)!=0 && (sleepVar-10)>0)
            sleepVar-=10;
        if(GetAsyncKeyState(VK_UP)!=0)
            sleepVar+=10;
    }
    getch();
    return 0;
}
