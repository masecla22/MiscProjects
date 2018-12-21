#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n,aa,imC=0,parC=0;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>aa;
        imC+=aa%2;
        parC+=((aa%2)==0);
    }
    cout<<abs(imC-parC);
    return 0;
}
