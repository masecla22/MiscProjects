#include <iostream>
#include <mattcore.h>

using namespace std;
using namespace matt::core;

int main()
{
    int cook=0;
    while(true)
    {
        ShowConsoleCursor(false);
        cout<<"Cookiezis: "<<cook<<" \r";
        cook++;
        _getch();
    }
    return 0;
}
