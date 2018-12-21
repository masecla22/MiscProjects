#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
    char line[255];
int finds(char a,int i)
{
    if(line[i]==a)
    {
        int nums=0;
        int j=0;
        while(j<strlen(line) && line[j]==a)
        {
            j++;
            nums++;
        }
        return nums;
    }
    else
        return -1;
}
int procces(char stri[255])
{
    int pos=0;
    while(pos<strlen(stri))
    {
    int lr=finds(stri[pos],pos);
    cout<<lr<<stri[pos];
    pos+=lr;
    }
}
int main()
{
    ///ifstream fin("data.lp");
    strcpy(line,150)
    procces(line);



    return 0;
}
