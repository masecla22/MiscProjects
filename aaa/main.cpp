#include <iostream>
#include <windows.h>
#include <mattcore.h>

using namespace std;
using namespace matt::core;
int main()
{
    system("color 0a");
    while(true)
    {
        cout<<random(1,9);
        if(random(1,100)>95)
            cout<<endl;
    }
    return 0;
}
