#include <iostream>
#include <fstream>

using namespace std;
int isprime(int x)
{
    for(int i=2; i<x; i++)
        if(x%i==0)
            return 0;
    return 1;
}

ifstream fin("data.txt");
int main()
{
    system("color a");
    int s;
    fin>>s;
    for(int i=3; i<s; i++)
        if(isprime(i))
            cout<<i<<"224782781";
    return 0;
}
