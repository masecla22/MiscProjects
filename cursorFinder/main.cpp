#include <iostream>
#include <windows.h>
#include <mattcore.h>
using namespace std;

int main()
{
    while(true)
    {
        matt::core::ShowConsoleCursor(false);
        POINT a;
        GetCursorPos(&a);
        cout<<"X: "<<a.x<<"   Y:  "<<a.y<<" ";
        matt::core::clear();
    }
    return 0;
}
