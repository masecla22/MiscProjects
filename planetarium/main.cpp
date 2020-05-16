#include <iostream>
#include "fap3d.h"
#include <windows.h>
#include <vector>
#include <ctime>
#include <random>
#include <cstring>
#include <graphics.h>
#include <sstream>

using namespace fap3d::setup;
using namespace fap3d::shapes::bidimensional;
using namespace fap3d::colors;
using namespace fap3d;

namespace space {
const int xoffset = 10;
const int yoffset = 20;
const bool titleVisible = true;
int FPS = 100;



int linesMade = 0;

class PlanetInformation {
public:
    Point position;
    Point pivot;
    double angularSpeed;
    double totalRotation;
    double sizes;
    std::string name;
    PlanetInformation(Point pos,Point piv,double angSpeed,std::string names,double size) {
        position = pos;
        pivot = piv;
        angularSpeed = angSpeed;
        totalRotation = 0;
        name = names;
        sizes = size;
    }
    PlanetInformation() {}
    void nextStep(void) {
        position.rotate(pivot,angularSpeed);
        totalRotation+=angularSpeed;
    }
};

class Moon {
public:
    Point position;
    std::string name;
    double angularSpeed;
    double totalRotation;
    double sizes;
    Moon(Point pos,std::string names,double angSpeed,double size) {
        position = pos;
        name = names;
        angularSpeed = angSpeed;
        totalRotation = 0;
        sizes = size;
    }
    void nextStep(PlanetInformation superPlanet) {
        position.rotate(superPlanet.pivot,superPlanet.angularSpeed);
        totalRotation+=angularSpeed;
        position.rotate(superPlanet.position,angularSpeed);
    }
    void renderName() {
        std::stringstream x;
        x<<name<<" rotations: "<<totalRotation/globals::PI2;
        char ap[257];
        x.getline(ap,257);
        outtextxy(xoffset+20,linesMade*yoffset,ap),linesMade++;
    }
    void selfRender() {
        shapes::bidimensional::Circle(position,sizes).draw();
        std::stringstream r;
        r<<name;
        char a[255];
        r.getline(a,255);
        outtextxy(position.getX(),position.getY(),a);
    }
};

class Planet {
public:
    PlanetInformation info;
    std::vector<Moon> moons;
    Planet(Point pos,Point piv,double angSpeed,std::string names,double size) {
        info = PlanetInformation(pos,piv,angSpeed,names,size);
    }
    void addMoon(Moon moon) {
        moons.push_back(moon);
    }
    Moon makeMoon(std::string name,double angularSpeed,int radius,double size) {
        return Moon(info.position.add(0,-radius),name,angularSpeed,size);
    }
    void nextStep() {
        info.nextStep();
        for(Moon &m : moons)
            m.nextStep(info);
    }
    void renderName() {
        std::stringstream x;
        x<<info.name<<" rotations: "<<info.totalRotation/globals::PI2;
        char ap[257];
        x.getline(ap,257);
        outtextxy(xoffset*2,linesMade*yoffset,ap),linesMade++;
        std::stringstream x1;
        char ap1[257];
        x1<<info.name;
        x1.getline(ap1,257);
        outtextxy(info.position.getX(),info.position.getY(),ap1);
        for(Moon &m : moons)
            m.renderName();
    }
    void selfRender() {
        shapes::bidimensional::Circle(info.position,info.sizes).draw();
        for(Moon &m : moons)
            m.selfRender();
    }
};


std::vector<Planet> activePlanets;

void addPlanet(Planet p) {
    activePlanets.push_back(p);
}

Planet getByName(std::string name) {
    for(Planet c : activePlanets)
        if(c.info.name==name)
            return c;
}
double getAngle(space::Planet pl) {
    double d = pl.info.totalRotation;
    while(d>fap3d::globals::PI2)
        d-=fap3d::globals::PI2;
    return d;
}
double abs(double a)
{
    return (a<0)?-a:a;
}
void reinitializeRenderer() {
    cleardevice();
    linesMade = 0;
    for(Planet &p:activePlanets) {
        p.nextStep();
        p.selfRender();
        p.renderName();
    }
    Sleep(1000.0/FPS);
}

void setFrameRate(int fps) {
    FPS = fps;
}
}

namespace constants {
const double earthSpeed = 0.001;
const double jupiterSpeed = earthSpeed/11.86;
const double europaSpeed = earthSpeed * 102.85835;
const double moonSpeed = earthSpeed * 13.354;
const double marsSpeed = earthSpeed / 1.88;
}

int main() {
    Window d = Window(0,0,900,600);
    d.open();
    using namespace constants;

    space::setFrameRate(5000);
    space::Planet sun = space::Planet(d.getCenter(),d.getCenter(),0,"Sun",30); ///Shut up i know it's a star

    space::Planet earth = space::Planet(d.getCenter().add(0,-170),d.getCenter(),earthSpeed,"Earth",20);
    space::Moon moon = earth.makeMoon("Moon",moonSpeed,40,10);

    earth.addMoon(moon);
    //space::Planet jupiter = space::Planet(d.getCenter().add(0,-250),d.getCenter(),jupiterSpeed,"Jupiter",30);
    //space::Moon europa = jupiter.makeMoon("Europa",europaSpeed,40,5);
    //jupiter.addMoon(europa);

    //space::Planet mars = space::Planet(d.getCenter().add(0,-140),d.getCenter(),marsSpeed,"Mars",10);

    space::addPlanet(sun);
    //space::addPlanet(jupiter);
    space::addPlanet(earth);
    //space::addPlanet(mars);


    while(true) {
        space::reinitializeRenderer();
        Sleep(1);
    }

    _getch();
    return 0;
}
