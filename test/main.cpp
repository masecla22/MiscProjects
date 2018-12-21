#include <iostream>
#include "mattgui.h"

using namespace std;

int main()
{
    cout<<"\033[2J"<<endl;
    cout<<getOsName();
    //gui("opt/1/2/3/4/");
    return 0;
}
