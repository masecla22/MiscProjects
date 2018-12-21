#include <iostream>
#include <settings.h>

using namespace std;
int o1=getValue("sets.in","o2");
int o2=getValue("sets.in","o2");
int o3=getValue("sets.in","o2");
int main()
{
    cout<<o1<<endl;
    Sleep(1000);
    chgValue("sets.in","o2",3);
    o1=getValue("sets.in","o2");
    cout<<o1<<endl;
    return 0;
}
