#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
int lines(char a[255])
{
  int number_of_lines = 0;
string line;
ifstream myfile(a);
while (getline(myfile, line))
    ++number_of_lines;
return number_of_lines;
}
ifstream fin("data.in");
fstream fout("data.out",ios::app);
int main()
{
int a=lines("data.in");
for(int i=0;i<a;i++)
{
    char s[255];
    fin>>s;
    if(strstr(s,"gmail")!=0)
    {
        fout<<s<<endl;
    }
}
    return 0;
}
