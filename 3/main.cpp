#include <iostream>
#include <windows.h>

using namespace std;
int contains3(int a)
{
    while(a>0)
    {
        int n=0;
        n=a%10;
        if(n==3)
            return 1;
        a/=10;
    }
    return 0;
}
int main()
{    long long n=1;
while(true)
{
    double contor=0;
    //cout<<contains3(13)<<endl;
    for(int i =1;i<=n;i++)
    {
        contor+=contains3(i);
    }
    cout<<double(contor*100/n)<<"%"<<endl;
    n*=10;
}
    return 0;
}
