#pragma once
#include <graphics.h>
#include <conio.h>
#include "shapes.h"
using fap3d::shapes::bidimensional::Point;
namespace fap3d{
namespace setup{
class Window{
private:
    int ix,iy;
    int iwidth,iheight;
public:
    void open(){
        initwindow(iwidth,iheight,"Fap3D Samplezz",ix,iy);
    }
    Window(int x,int y,int width,int height){
        ix = x;
        iy = y;
        iwidth = width;
        iheight = height;
    }
    Point getCenter(){return Point(iwidth/2,iheight/2);}

};
}
}
