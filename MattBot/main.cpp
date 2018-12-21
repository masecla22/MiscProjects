#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;
int main()
{
    int n=1,dec,i=1,iter=1,advmode=0;
    if(advmode==0)
    {
    cout<<"Decimals: ";
    cin>>dec;
    cout<<"Speed of iterations: ";
    cin>>iter;
    int decr = dec+1;
    int ssh=0;
    while(2)
    {
        double pi=0;
        for(float k=1; k<=n; k+=2)
        {
            if(i%2==0)pi-=4/k;
            else pi+=4/k;
            i++;
        }
        if(pi<0)pi*=-1;
        else pi*= 1;
                cout<<setprecision(decr)<<"pi= "<<pi<<" Gained using "<<n<<" iterations rated at "<<dec<<" decimals    \r";
        n+=iter;
    }
    }
    else
    {
          cout<<"Decimals: ";
    cin>>dec;
    cout<<"Speed of iterations: ";
    cin>>iter;
    int decr = dec+1;
    cout<<"\ndecr=dec+1; Old: "<<decr<<" New: "<<dec+1;
    int ssh=0;
    while(2)
    {
        double pi=0;
        for(float k=1; k<=n; k+=2)
        {
            if(i%2==0)pi-=4/k;
            else pi+=4/k;
            i++;
        }
        if(pi<0)pi*=-1;
        else pi*= 1;
                cout<<setprecision(decr)<<"pi= "<<pi<<" Gained using "<<n<<" iterations rated at "<<dec<<" decimals    \r";
        n+=iter;
    }
    }
    return 0;
}
