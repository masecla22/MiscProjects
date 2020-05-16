#pragma once
#include <cmath>
#include <vector>
#include "globals.h"
namespace fap3d {
namespace shapes {
class Shape {
    void draw();
};
namespace bidimensional {
class Point : Shape {
  private:
    double ix,iy;
  public:
    Point(double x,double y) {
        ix = x,iy = y;
    }
    void draw() {
        putpixel(ix,iy,globals::color);
    }
    void setX(double x) {
        ix = x;
    }
    void setY(double y) {
        iy = y;
    }
    double getX() {
        return ix;
    }
    double getY() {
        return iy;
    }
    Point add(double x,double y) {
        return Point(ix+x,iy+y);
    }
    Point add(Point point)
    {
        return Point(ix+point.ix,iy+point.iy);
    }
    void rotate(Point origin,double angle) {
        double rotatedX = cos(angle) * (ix-origin.getX())-sin(angle)*(iy-origin.getY())+origin.getX();
        double rotatedY = sin(angle) * (ix-origin.getX())+cos(angle)*(iy-origin.getY())+origin.getY();
        ix = rotatedX;
        iy = rotatedY;
    }
    Point getMiddle(Point b) {
        return Point((ix+b.getX())/2,(iy+b.getY())/2);
    }
    double getLength(Point b) {
        return sqrt((ix-b.ix)*(ix-b.ix)+(iy-b.iy)*(iy-b.iy));
    }
    double getRawLength(Point b) {
        return (ix-b.ix)*(ix-b.ix)+(iy-b.iy)*(iy-b.iy);
    }
    Point(){ix=0,iy=0;}
};
class Line : Shape {
  private:
    Point ia,ib;
  public:
    Line(Point a,Point b) {
        ia = a,ib = b;
    }
    Point getA() {
        return ia;
    }
    Point getB() {
        return ib;
    }
    void draw() {
        line(ia.getX(),ia.getY(),ib.getX(),ib.getY());
    }
    void rotate(Point origin,double angle) {
        ia.rotate(origin,angle),ib.rotate(origin,angle);
    }
    double getLength() {
        return ia.getLength(ib);
    }
    double getRawLength() {
        return ia.getRawLength(ib);
    }
};
class Circle : Shape {
  private:
    Point ipos;
    double irads;
  public:
    void draw() {
        circle(ipos.getX(),ipos.getY(),irads);
    }
    void rotate(Point origin,double angle) {
        ipos.rotate(origin,angle);
    }
    Circle(Point position,double rads){
        ipos=position,irads=rads;
    }
    Circle(double x,double y,double rads){
        ipos=Point(x,y),irads=rads;
    }
};
class Ellipse : Shape {
  private:
    Point ipos,isize;
  public:
    void draw() {
        ellipse(ipos.getX(),ipos.getY(),0,0,isize.getX(),isize.getY());
    }
    void rotate(Point origin,double angle) {
        ipos.rotate(origin,angle);
    }
    Ellipse(Point position,Point size){
        ipos = position,isize = size;
    }
    Ellipse(double x,double y,double xrad,double yrad){
        Ellipse(Point(x,y),Point(xrad,yrad));
    }
    Ellipse(Point position,double xrad,double yrad){
        Ellipse(position,Point(xrad,yrad));
    }
    Ellipse(double x,double y,Point size){
        Ellipse(Point(x,y),size);
    }
};
class Rect : Shape {
  private:
    Point a,b,c,d;
    double oheight,owidth;
  public:
    Rect(double x,double y,double height,double width):a(x,y),b(x+width,y),c(x+width,y+height),d(x,y+height),oheight(height),owidth(width){}
    Rect(Point position,Point size):Rect(position.getX(),position.getY(),size.getX(),size.getY()){}
    Rect(double x,double y,Point size):Rect(x,y,size.getX(),size.getY()){}
    Rect(Point position,double height,double width):Rect(position.getX(),position.getY(),height,width){}
    void draw() {
        Line(a,b).draw();
        Line(b,c).draw();
        Line(a,d).draw();
        Line(c,d).draw();
    }
    void rotate(Point origin,float rads) {
        a.rotate(origin,rads),b.rotate(origin,rads),c.rotate(origin,rads),d.rotate(origin,rads);
    }
    Point getCenter() {
        return a.getMiddle(b).getMiddle(c.getMiddle(d));
    }
    Point getFirstCorner()  {
        return a;
    }
    Point getSecondCorner() {
        return b;
    }
    Point getThirdCorner()  {
        return c;
    }
    Point getFourthCorner() {
        return d;
    }
};
class Square: Shape {
  private:
    Point a,b,c,d;
    double osize;
  public:
    Square(double x,double y,double size):a(x,y),b(x+size,y),c(x+size,y+size),d(x,y+size) {
        a = Point(x,y);
        b = Point(x+size,y);
        c = Point(x+size,y+size);
        d = Point(x,y+size);
        osize=size;
    }
    Square(Point position,double size):Square(position.getX(),position.getY(),size) {}
    void draw() {
        Line(b,c).draw();
        Line(a,b).draw();
        Line(c,d).draw();
        Line(d,a).draw();
    }
    void rotate(Point origin,double rads) {
        a.rotate(origin,rads),b.rotate(origin,rads),c.rotate(origin,rads),d.rotate(origin,rads);
    }
    Point getCenter() {
        return a.getMiddle(b).getMiddle(c.getMiddle(d));
    }
    Point getFirstCorner()  {
        return a;
    }
    Point getSecondCorner() {
        return b;
    }
    Point getThirdCorner()  {
        return c;
    }
    Point getFourthCorner() {
        return d;
    }
};
class Trail : Shape {
  private:
    std::vector<Point> points;
  public:
    Trail() {
        points = std::vector<Point>();
    }
    void addPoint(Point p) {
        points.push_back(p);
    }
    void drawPoints() {
        for(Point p : points)
            p.draw();
    }
    void draw() {
        for(unsigned int i=0; i<points.size()-1; i++) {
            Line(points[i],points[i+1]).draw();
        }
    }
    Point pop_last() {
        Point aux = points.at(points.size()-1);
        points.pop_back();
        return aux;
    }
    void emptyTrail() {
        points = std::vector<Point>();
    }
    int getTrailSize() {
        return points.size();
    }
    double getTrailLength() {
        double cont = 0;
        for(unsigned int i=0; i<points.size()-1; i++)
            cont+=points[i].getLength(points[i+1]);
        return cont;
    }
    double getRawTrailLength() {
        double cont = 0;
        for(unsigned int i=0; i<points.size()-1; i++)
            cont+=points[i].getRawLength(points[i+1]);
        return cont;
    }
    void rotate(Point origin,double angle) {
        for(Point &p:points)
            p.rotate(origin,angle);
    }
};
class RegularPolygon : Shape {
  private:
    std::vector<Point> points;
    double length;
  public:
    RegularPolygon(Point position,int sides,double sideLength) {
        double angle = (((sides-2.0)*180.0)/sides)*fap3d::globals::PI/180.0;
        Point pos1=position,pos2 = position.add(sideLength,0);
        for(int i=0; i<sides; i++) {
            if(i%2==0)
                points.push_back(pos1),pos1.rotate(pos2,angle);
            if(i%2==1)
                points.push_back(pos2),pos2.rotate(pos1,angle);
        }
    }
    void draw() {
        Line(points[0],points[points.size()-1]).draw();
        for(unsigned int i=0; i<points.size()-1; i++) {
            Line(points[i],points[i+1]).draw();
        }
    }
    void rotate(Point origin,double angle) {
        for(Point &p:points)
            p.rotate(origin,angle);
    }
    Point getCenter() {
        if(points.size()%2==1)
            return points[0].getMiddle(points[points.size()/2].getMiddle(points[points.size()/2+1]));
        if(points.size()%2==0)
            return points[0].getMiddle(points[points.size()/2]);
    }
};
class Turtle : Shape {
private:
    double iangle;
    Point iposition;
    bool pendown;
public:
    Turtle(Point position,double angle=0,bool isPenDown=true):iposition(0,0){
        iposition = position;
        iangle = angle;
        pendown = true;
    }
    void putPen(bool down){pendown=down;}
    void raisePen(){pendown=false;}
    void lowerPen(){pendown=true;}
    void flipPen(){pendown=(pendown==0);}
    void moveForward(double amount)
    {
        Point ips = iposition;
        iposition = Point(iposition.getX()+amount*cos(iangle),iposition.getY()+amount*sin(iangle));
        if(pendown)
        {
            Line(iposition,ips).draw();
        }
    }
    void draw(){
        Line(iposition,iposition.add(20,20)).draw();
    }
    void right(double angle)
    {
        iangle+=angle;
        while(iangle<globals::PI2)
            iangle-=globals::PI2;
    }
    void left(double angle)
    {
        iangle-=angle;
    }
    void rotate(Point origin,double angle)
    {
        Point ips = iposition;
        iposition.rotate(origin,angle);
        if(pendown)
        {
            Line(iposition,ips).draw();
        }
    }
};
}
namespace tridimensional {
class Vector {
    int ii,ij,ik;
  public:
    Vector(int i,int j,int k) {
        ii=i;
        ij = j;
        ik = k;
    }
    Vector add(int i,int j,int k) {
        return Vector(ii+i,ij+j,ik+k);
    }
    Vector multiply(int i,int j,int k) {
        return Vector(ii*i,ij*j,ik*k);
    }
};
class Point {
    int ix,iy,iz;
  public:
    Point(int x,int y,int z) {
        ix = x;
        iy = y;
        iz = z;
    }
};
}
}
}
