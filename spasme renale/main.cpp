#include <iostream>
#include <mattcore.h>
#include <graphics.h>
#include <vector>
#include <cmath>
#include <random>

using namespace std;

double spreadRate = 2;
int uptodown[3] = {450,550};

int main() {
    initwindow(900,600,"Teren",100,100);
    while(true) {
        vector<int> a;
        for(int i=0; i<1000; i++)
            a.push_back(matt::core::random(uptodown[0],uptodown[1]));

        for(float i=0; i<990; i+=1) {
            default_random_engine engine{ static_cast<unsigned int>(time(NULL)) };
            uniform_real_distribution<double>randomNumber{ 0,0 };
            a.push_back(randomNumber(engine));
            line(i*spreadRate,a.at(i),(i+1)*spreadRate,a.at(i+1));
        }
        spreadRate+=1;
        Sleep(200);
        cleardevice();
    }


    _getch();

    return 0;
}

