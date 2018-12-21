#include <iostream>
#include <cstring>
#include <fstream>

using namespace std;
char FileExists(char name[255])
{
    ifstream ifile(name);
    if (ifile)
        return 1;
    return 0;
}

char registers(char user[255],char pass[255])
{
    char FileNM[255];
    strcpy(FileNM,"Accs\\");
    strcat(FileNM,user);
    strcat(FileNM,".txt");
    if(FileExists(FileNM)==0)
    {
        ofstream fout(FileNM);
        fout<<pass;
        return 1;
    }
    else
        return 0;
}
char login(char user[255],char pass[255])
{
    char FileNM[255];
    strcpy(FileNM,"Accs\\");
    strcat(FileNM,user);
    strcat(FileNM,".txt");
    if(FileExists(FileNM)==1)
    {
        fstream file(FileNM, ios::in | ios::out | ios::app);
        char pass1[255];
        file>>pass1;
        if(strcmp(pass,pass1)==0)
        {
            return 1;
        }
        return 0;
    }
    else
        return 0;
}
int main()
{
    int a = registers("masecla","123456");
    cout<<a;

    return 0;
}
