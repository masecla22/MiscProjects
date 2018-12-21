#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>

using namespace std;

int main()
{
    double pi=1;
    int i=1;
    int method=2;
    if(method==1)
    while(true)
    {
        double raport=(1/double(i*2+1));
        if(i%2==1)
        {
            pi-=raport;

        }
        else
        {
            pi+=raport;
        }
        i++;
        cout<<fixed<<setprecision(40)<<"PI: "<<pi*4<<"  TAU:"<<pi*8;
        Sleep(1);
        cout<<"  \r";
    }
    if(method==2)
    while(true)
    {
        double pi=1;
        double s=i;
        s*=4*i;
        pi*=double(s/(s-1));
        cout<<fixed<<setprecision(40)<<"PI: "<<pi*4<<"  TAU:"<<pi*8;
        Sleep(1);
        cout<<"  \r";
        i++;
    }
    return 0;
}
