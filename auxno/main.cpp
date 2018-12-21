#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>
#include <stdlib.h>
#include <bits/stdc++.h>
#include <conio.h>
using namespace std;
int compare(char a[255],char b[255])
{
    b[strlen(a)-1]='\0';
    int prb=0;
    for(int i=0; i<strlen(a); i++)
    {
        if(a[i]==b[i])
            prb++;
    }
    return (100*strlen(a))/prb;
}
ifstream f("parola404.in");
const string denyMess = "MESAGGE FOR NOT ENTERING CORRECTLY";
const string enterMess = "MESSAGE FOR LOGGING IN";
void trueCin(char buff[255])
{
    char theStr[255];
    int crrPos=0;
    while(true)
    {
        int a = getch();
        if(a==13){
            if(crrPos!=0)
            break;
        }
        else if(a==8)
            if(crrPos!=0)
            crrPos--;
        else
        {
            theStr[crrPos]=char(a);
            theStr[(crrPos+1)]='\0';
            cout<<"*";
        }
    }
}
int main()
{
    char pass[255];
    trueCin(pass);
    cout<<pass<<endl;
    /**
    HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
    WORD wOldColorAttrs;
    CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
    char s[255],s2[255];
    f.getline(s,255);
    while(true)
    {
        cin.getline(s2,255);
        if(strcmp(s,s2)==0)
        {
            SetConsoleTextAttribute(h,10);
            cout<<enterMess<<endl;
            SetConsoleTextAttribute ( h,7);
            break;
        }
        if(strcmp(s,s2)!=0 && strlen(s2)!=0)
        {
            SetConsoleTextAttribute(h,FOREGROUND_RED);
            cout<<denyMess<<endl;
            SetConsoleTextAttribute ( h,7);
        }

    }
    */
    return 0;
}
