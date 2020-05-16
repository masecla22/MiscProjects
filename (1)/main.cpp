#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;
int divs(int n)
{
    int cnt = 0;
    for (int i = 1; i*i <= n; i++) {
        if (n % i == 0) {
            if (n / i == i)
                cnt++;

            else
                cnt = cnt + 2;
        }
    }
    return cnt;
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
