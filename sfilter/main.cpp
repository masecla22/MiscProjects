#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int iswear(char a[255])
{
    char wordlist[255][20]={"ass","fuck","shit","dick","cock","shet","fck","fack","fak","nigga","nigger","anus","bitch","cunt","fk","kill yourself","kill urself"};
    int numofwords=17;
    for(int i=0; i<numofwords; i++)
        if(int(strstr(a,wordlist[i])))
        return 1;
    return 0;
}
void convert(char a[255])
{
    for(int i=0; i<int(strlen(a)); i++)
    {
        a[i]=tolower(a[i]);
        if(a[i]=='$')a[i]='s';
        if(a[i]=='@'||a[i]=='4')a[i]='a';
        if(a[i]=='!')a[i]='i';
        if(a[i]=='0')a[i]='o';
        if(a[i]=='3')a[i]='e';
    }
}
int hasdots(char a[255])
{
    for(int i=0;i<strlen(a);i++)
    {

    }
}
int islink(char a[255])
{
    int probability=0;
    char allowedsites[255][20]={};
    if(int(strstr(a,"http"))||int(strstr(a,"://"))||int(strstr(a,"www.")))
    {
        probability+=50;
    }
}
int main()
{
    char a[255];
    cin.getline(a,255);
    convert(a);
    cout<<iswear(a)<<endl;
    return 0;
}
