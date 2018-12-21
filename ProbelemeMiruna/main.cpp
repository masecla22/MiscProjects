#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int min1=999999999;
    int min2=999999999;
    int min3=999999999;
    while(n!=0)
    {
        int oglind = 0;
        int copien = n;
        while(copien!=0)
        {
            oglind+=copien%10;
            copien/=10;
            oglind*=10;
        }
        oglind/=10;
        cin>>n;
    }
    return 0;
}
