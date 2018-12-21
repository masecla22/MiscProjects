#include <iostream>
#include <cstring>
#include <windows.h>

using namespace std;

int main()
{
    char a = 'a';
    int i=1;
while(2)
{
    cout<<a-i<<" = "<<char(a-i)<<" so "<<i<<"\t\t";
    if(i==100)
        break;
    i++;
    Sleep(50);
}
    return 0;
}
