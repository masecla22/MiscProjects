#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <windows.h>

using namespace std;
///Done Function
int lines(char a[255])
{

    int number_of_lines = 0;
    std::string line;
    std::ifstream myfile(a);

    while (std::getline(myfile, line))
        ++number_of_lines;
    return number_of_lines;
}
///Done Function
int starts(char a[255],char b[255])
{
    if(strstr(a,b)==a)
        return 1;
    return 0;
}

int getarg(char a[255],char b[255],int num)
{
    num++;
    char *p;
    int i=1;
    for(p=strtok(a,", "); p; p=strtok(NULL,", "))
    {
        if(i==num)
            strcpy(b,p);
        i++;
    }

}
int intr(char a[255])
{
    if(starts(a,"start")==1)
    {
        cout<<"Start command detected"<<endl;
        char arg[255],arg1[255];
        char cpy[255];
        strcpy(cpy,a);
        getarg(cpy,arg,1);
        strcpy(cpy,a);
        getarg(a,arg1,2);
        int i=0;
        int so=atoi(arg1);
        char comm[255];
        strcpy(comm,"start ");
        strcat(comm,arg);
        while(i<so)
        {
            system(comm);
            i++;
        }
    }

    if(starts(a,"mmouse")==1)
    {
                cout<<"mmouse command detected"<<endl;
        char arg[255],arg1[255];
        char cpy[255];
        strcpy(cpy,a);
        getarg(cpy,arg,1);
        strcpy(cpy,a);
        getarg(a,arg1,2);
        int xaxis=atoi(arg);
        int yaxis=atoi(arg1);
        SetCursorPos(xaxis,yaxis);
    }
    if(starts(a,"cfile")==1)
    {
                cout<<"cfile command detected"<<endl;
        char arg[255];
        char cpy[255];
        strcpy(cpy,a);
        getarg(cpy,arg,1);
        ofstream eofjhefbefowhbiiu(arg);
    }
    if(starts(a,"cdir")==1)
    {
        cout<<"cdir command detected"<<endl;
        char arg[255];
        char cpy[255];
        strcpy(cpy,a);
        getarg(cpy,arg,1);
        char comm[255];
        strcpy(comm,"mkdir ");
        strcat(comm,arg);
        system(comm);
    }
    if(starts(a,"delay")==1)
    {
        cout<<"delay command detected"<<endl;
        char arg[255];
        char cpy[255];
        strcpy(cpy,a);
        getarg(cpy,arg,1);
        int i=atoi(arg);
        Sleep(i);
    }
    if(starts(a,"sdelay")==1)
    {
        cout<<"sdelay command detected"<<endl;
        char arg[255];
        char cpy[255];
        strcpy(cpy,a);
        getarg(cpy,arg,1);
        int i=atoi(arg);
        i*=1000;
        Sleep(i);
    }
}
int main()
{
    char a[255];
    int i=lines("code.in");
    int j=1;
    ifstream fin("code.in");
    while(j<=i)
    {
        fin.getline(a,254);
        intr(a);
        j++;
    }
/// start bat.exe 3
    return 0;
}
