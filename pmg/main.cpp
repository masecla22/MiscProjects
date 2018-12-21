#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    double n;
    for(int k=2; k<56; k++)
    {
        double suma=0;
        for(int i=1; i<k; i++)
            suma+=((1/pow(2,i)));
        cout<<setw(57)<<setprecision(53)<<suma;
        cout<<setprecision(53)<<suma<<".0"<<endl;
    }
    return 0;
}
