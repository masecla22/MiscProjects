#include <iostream>
#include <windows.h>
#include <mattcore.h>
using namespace std;

char toUse = {'#',' '}

void times(int time) {
    int i=0;
    while(i<time) {
        cout<<toUse[0];
        i++;
    }
}
void spc(int times)
{
    int i=0;
    while(i<times) {
        cout<<" ";
        i++;
    }
}
int howManytoPop = 10;
int perc = 100;
int main() {
    int i=1;
    while(i<=perc) {
        matt::core::ShowConsoleCursor(false);
        times(i/(perc/howManytoPop));
        spc(howManytoPop+5-i/(perc/howManytoPop));
        cout<<i<<"%  \r";
        i++;
        Sleep(50);
    }
    return 0;
}
