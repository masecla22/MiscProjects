#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("file.in");
    int a[100][100];
    int x,y;
    cin>>x,y;
    for(int j=0; j<y; j++)
        for(int i=0; i<x; i++)
            cin>>a[y][x];
            return 0;
}
