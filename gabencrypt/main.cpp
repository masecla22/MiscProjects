#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

int main()
{
    int n=0;
    cin>>n;
    if(n==0)
    {

    char a[255];
    cin.get();
    cin.getline(a,255);
    for(int i=0;a[i]!='\0';i++)
    {
        for(int j=0;j<int(a[i]);j++)
            cout<<setw(3)<<"gaben";
        cout<<"\n";
    }
    }
    if(n==1)
    {

    }
    return 0;
}
