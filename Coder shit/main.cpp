#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<string.h>
#include<fstream>
#include<dirent.h>
#include <windows.h>
#include "mattcore.h"
using namespace std;
void showString(char a[255])
{
    for(int i=0; a[i]!=0; i++)
    {
        cout<<a[i];
        Sleep(matt::core::random(1,5));
    }
    cout<<endl;
}
void showFile(char file[255])
{
    ifstream fin(file);
    char a[255];
    while(fin.getline(a,255))
    {
        if(matt::core::random(50,100)>matt::core::random(20,60))
            showString(a);
        else
            cout<<a<<endl;
        Sleep(10);
    }
}
int main()
{
    matt::core::ShowConsoleCursor(0);
    system("color 0a");
    for(int i=0; i<20; i++)
    {
        DIR *d;
        char *p1,*p2;
        int ret;
        struct dirent *dir;
        d = opendir(".");
        if (d)
        {
            while ((dir = readdir(d)) != NULL)
            {
                p1=strtok(dir->d_name,".");
                p2=strtok(NULL,".");
                if(p2!=NULL)
                {
                    ret=strcmp(p2,"h");
                    if(ret==0)
                    {
                        char a[255];
                        strcpy(a,p1);
                        strcat(a,".");
                        strcat(a,p2);
                        showFile(a);
                    }
                }
            }
            closedir(d);
        }
        if(i==4)
        {
            Sleep(3000);
            system("color 0c");
            Sleep(3000);
        }
    }
    return 0;
}

