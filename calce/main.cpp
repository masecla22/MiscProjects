#include <iostream>
using namespace std;
int main() {
    int n;
    cin>>n;
    int prev = 101;
    int cr=0,ms=0;
    for(int i=0;i<n;i++)
    {
        int el;
        cin>>el;
        if(prev==101){
            prev=el;
            continue;
        }
        if(el>prev)
        {
            cr++;
            if(cr>ms)
                ms=cr;
        }
        else
            cr=0;
        prev=el;
    }
    cout<<ms;
    return 0;
}
