#include <iostream>
#include <mattcore.h>

using namespace std;

int main()
{
    while(2)
    {
        matt::core::ShowConsoleCursor(false);
        matt::core::clear();
        cout<<"X: "<<matt::core::getMouseX()<<" Y: "<<matt::core::getMouseY()<<"       "<<endl;
    }
    return 0;
}
