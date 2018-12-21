#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;
int divs(int a)
{
    int how=0;
    for(int j=2; j<=a; j++)
    {
        if(a%j==0)
            how++;
        cout<<"Current number: "<<a<<" Dividers found: "<<how<<" Current operation: "<<a<<"/"<<j<<"\r";
        }
    return how;
}
int main()
{
    int a=INT_MAX;
    int maxi;
    maxi=0;
    for(int i=0; i<a; i++)
    {
        int how=divs(i);
        if(how>maxi)
        {
            cout<<"                                                                                        \r";
            cout<<i<<" "<<how<<endl;
            maxi=how;
        }
    }
    return 0;
}
