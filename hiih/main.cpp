#include <iostream>
#include <fstream>

using namespace std;
void showFile(char file[255])
{
    ifstream fin(file);
    char a[255];
    while(fin.getline(a,255))
    {
        cout<<a<<endl;
    }
}
int main()
{
    showFile("logo.txt");
    return 0;
}
