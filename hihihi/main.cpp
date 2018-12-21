#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char a[255],b[255],ch;
    cin.getline(a,255);
    cin>>b>>ch;
    if(ch=='e'){for(int i=0; i<strlen(a); i++){int x=i%strlen(b);a[i]+=b[x];}}
    if(ch=='d'){for(int i=0; i<strlen(a); i++){int x=i%strlen(b);a[i]-=b[x];}}
    cout<<a;
    return 0;
}
