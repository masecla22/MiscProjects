#include <iostream>
using namespace std;
int sol[10],n;
int main() {

    int i;
    cin>>n;
    while(n>0) {
        if(!sol[n%10])
            sol[n%10]=1;
        n/=10;
    }
    for(i=0; i<=9; i++)
        if(sol[i])
            cout<<i<<" ";
    return 0;
}
