#include <iostream>
#include <mattcore.h>

using namespace std;
using namespace matt::core;

int main()
{
    ShowConsoleCursor(false);
    while(true){
        int x = getMouseX();
        int y = getMouseY();
        cout<<"X: "<<x<<" Y: "<<y<<"  \r";
        if(GetAsyncKeyState(13)!=0){
            cout<<endl;
            Sleep(200);
        }
    }
    return 0;
}
