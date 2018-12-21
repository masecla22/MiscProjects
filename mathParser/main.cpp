#include <iostream>

using namespace std;
bool basicCheck(string a)
{
    int oPC=0;
    int cPC=0;
    for(int i=0;i<a.length();i++)
    {
        oPC+=a.at(i)=='(';
        cPC+=a.at(i)==')';
    }
    if(oPC!=cPC)
        return 0;
    return 1;
}

int main()
{
    string a;
    cin>>a;

    return 0;
}
