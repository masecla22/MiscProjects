#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    ofstream fout("output.txt");
    for(int i=1;i<300;i++)
    {
        fout<<"    - prestige"<<i<<endl;
    }
    return 0;
}
