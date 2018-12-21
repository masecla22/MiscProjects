#include <iostream>
#include <mattmark.h>
#include "mattsets.h"
using namespace std;
using namespace matt::settings;

int main()
{
    /**
    matt::benchmark::clock a;
    a.start();
    for(int i=0;i<10000;i++)
        getValue("sets.in","a");
    cout<<getValue("sets.in","a")<<endl;
    a.ends();
    cout<<a.durs;
    */
    cout<<matt::core::stoa(200);

    return 0;
}

