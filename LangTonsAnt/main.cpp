#include "taw.h"
#include <mattmark.h>
#include <ctime>
using namespace std;


int main()
{
    initwindow(1000,1000,"LangTonAnt",100,40);
    board ff;
    matt::benchmark::clock a;
    ant f;
    a.start();
    for(;1;)
    {
        if(GetAsyncKeyState(0x45)){
            Sleep(300);
            if(GetAsyncKeyState(0x45))
                break;
        }
        f.nextRun(ff);
    }
    return 0;
}
