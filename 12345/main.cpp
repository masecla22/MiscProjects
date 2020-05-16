#include <iostream>
#include <windows.h>
#include <mattcore.h>
using namespace std;

std::string loaded = "\\";
std::string unloaded = "/";

void times(int time) {
    int i=0;
    while(i<time) {
        cout<<loaded;
        i++;
    }
}
void spc(int times) {
    int i=0;
    while(i<times) {
        cout<<unloaded;
        i++;
    }
}
double howManytoPop = 25;
double perc = 100;
int main() {
    int i=1;
    while(i<=perc) {
        matt::core::ShowConsoleCursor(false);
        times(i/(perc/howManytoPop));
        spc(howManytoPop-i/(perc/howManytoPop));
        cout<<"  ";
        cout<<i<<"%    \r";
        i++;
        Sleep(50);
    }
    return 0;
}
