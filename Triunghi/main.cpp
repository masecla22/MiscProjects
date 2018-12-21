#include <iostream>
using namespace std;
int main()
{
    int a;
    cin>>a;
    int j=0;
    while(j<a){
        int spatii = a-1-j;
        for(int h=0;h<spatii;h++)cout<<" ";
        for(int g=0;g<j*2+1;g++)cout<<"*";
        cout<<endl;
        j++;
    }

    j=1;
    while(j<a){
        int spatii = j;
        for(int h=0;h<j;h++)cout<<" ";
        for(int g=0;g<(a-j)*2-1;g++)cout<<"*";
        cout<<endl;
        j++;
    }
    return 0;
}
