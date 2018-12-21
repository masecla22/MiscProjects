#include <iostream>
#include "mattNet.h"

std::ifstream fin("output.txt");
int main()
{
    char a[255];
    std::cin.getline(a,255);
    getSource(a);
    Sleep(2000);
    while(!fin.eof())
    {
        std::string line;
        getline(fin,line);
        std::cout<<line<<"\n";
    }
    return 0;
}
