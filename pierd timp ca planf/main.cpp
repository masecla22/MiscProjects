#include <iostream>
#include <graphics.h>
#include <vector>
#include <conio.h>
#include <random>
#include <algorithm>
#include <cmath>

using namespace std;
int window_width = 900;
int window_height = 600;
void drawRect(int xCoord,int height,int width) {

    for(int i=0; i<height; i++)
        line(xCoord,window_height-i,xCoord+width,window_height-i);
}
void clearRect(int xCoord,int width){
    setcolor(0);
    for(int i=0; i<window_height; i++)
        line(xCoord,window_height-i,xCoord+width,window_height-i);
    setcolor(15);
}
void render(std::vector<int> vect) {
    cleardevice();
    for(int i=0; i<vect.size(); i++)
        drawRect(i*(double)window_width/(double)vect.size(),(double)vect[i],(double)window_width/(double)vect.size());
}
void shuffle(std::vector<int> &vect) {
    auto rng = std::default_random_engine {};
    std::shuffle(std::begin(vect), std::end(vect), rng);
}
void renderOnly(std::vector<int> &vect,int pos)
{
    clearRect(pos*(double)window_width/(double)vect.size(),(double)window_width/(double)vect.size());
    drawRect(pos*(double)window_width/(double)vect.size(),(double)vect[pos],(double)window_width/(double)vect.size());
}
void sorts1(std::vector<int> &vect) {
    for(int i=0; i<vect.size(); i++) {
        for(int j=i+1; j<vect.size(); j++) {
            if(vect[i]>vect[j]) {
                swap(vect[i],vect[j]);
                renderOnly(vect,i);
                renderOnly(vect,j);
            }
        }
    }
    render(vect);
}
void sorts(std::vector<int> &a) {
   bool swapp = true;
    while(swapp)
    {
        swapp = false;
        for (int i = 0; i < a.size()-1; i++)
        {
            if (a[i]>a[i+1] )
            {
                swapp = true;
                swap(a[i],a[i+1]);
                //renderOnly(a,i);
                //renderOnly(a,i+1);
            }
        }
        if(rand()%200==0)
        render(a);
    }
}
int main() {

    initwindow(900,600,"aaa",100,100);
    std::vector<int> vect;
    for(int i=1; i<600; i++)
        vect.push_back(i*1);
    render(vect);
    Sleep(20);
    shuffle(vect);
    render(vect);
    sorts(vect);
    render(vect);
    _getch();
    return 0;
}
