

#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include <windows.h>
#include <ctime>
#include <algorithm>
#define cls system("cls")
using namespace std;
int howmany=4;
void setall(char what[1000],char iwhat,int howmany)
{
    char mess[1000];
    for(int i=0; i<howmany; i++)mess[i]=iwhat;
    mess[howmany]='\0';
    strcpy(what,mess);
}
int howmanyc(char a[255], char b)
{
    int bs=0;
    for(int i=0; i<int(int(strlen(a))); i++)
        if(a[i]==b) bs++;
    return bs;
}
int random(int min, int max)
{
    return min + (rand() % static_cast<int>(max - min + 1));
}
int srandom(int min, int max,char a[255])
{
    return min + (rand() % static_cast<int>(max - min + 1))+int(strlen(a))+int(a[3]);
}
int toint(int a)
{
    char f[2];
    itoa(a,f,10);
    return f[0];
}
int gethowmany()
{
    return howmany;
}
char tochar(char a)
{
    return int(a)-48;
}
void autogen(char a[255],int longness)
{
    int i=0;
    while(i<longness)
    {
        int lol=toint(random(1,howmany));
        if(lol!=a[(i-1)])a[i++]=lol;
    }
    a[longness]='\0';
}
void swt(char a[255],int pos1, int pos2)
{
    char aux;
    aux = a[pos1];
    a[pos1]=a[pos2];
    a[pos2]=aux;
}
void loading(char a[255])
{
    for(int i=0; i<=100; i++)
    {
        cout<<"Loading "<<a<<" "<<i<<"%\r";
        Sleep((30+random(0,100)));
    }
    cout<<endl;
}
void cpyto(char a[255],char a1[255],int to)
{
    for(int i=0; i<to; i++)a[i]=a1[i];
}
void up(char &a)
{
    if(!(tochar(a)>=(howmany+2)))a++;
}
int isall(char a[255],int what)
{
    for(int i=0; i<int(int(strlen(a))); i++)if(!(a[i]==toint(what)))return 0;
    return 1;
}
int arelast(char a[255])
{
    for(int i=(int(strlen(a))-1); i>=0; i--)if(tochar(a[i])!=howmany)return int(strlen(a))-i-1;
    return int(strlen(a));
}
void nextKey(char a[255])
{
    up(a[(int(strlen(a))-1)]);
    for(int i=(int(strlen(a))-1); i>=0; i--)
        if(a[i]==toint((howmany+1)))
        {
            a[i]='1';
            up(a[(i-1)]);
        }
}
void nextSKey(char a[255])
{
if(howmanyc(a,'3')!=0)
{
    while(howmanyc(a,'1')>=2 || howmanyc(a,'4')>=2)
    {
        nextKey(a);
    }
}
else
    nextKey(a);
}
void encrypt1(char a[255])
{
    for(int i=0; i<int(strlen(a))/2; i++)
    {
        char temp=a[i];
        a[i]=a[int(strlen(a))-i-1];
        a[int(strlen(a))-i-1]=temp;
    }
}
void encrypt2(char a[255])
{
    for(int i=0; i<int(strlen(a)); i++)a[i]+=3;
}
void encrypt3(char a[255],char key[255])
{
    for(int i=0; i<int(strlen(a)); i++)a[i]+=int(strlen(a));
}
void encrypt4(char a[255])
{
    for(int i=0; i<int(strlen(a))-1; i+=2)swt(a,i,(i+1));
}
void decrypt1(char a[255])
{
    encrypt1(a);
}
void decrypt2(char a[255])
{
    for(int i=0; i<int(strlen(a)); i++)a[i]-=3;
}
void decrypt3(char a[255],char key[255])
{
    for(int i=0; i<int(strlen(a)); i++)a[i]-=int(strlen(a));
}
void decrypt4(char a[255])
{
    encrypt4(a);
}
void encrypt5(char a[255])
{
    char a1[255];
    int j=0;
    for(int i=0; i<int(strlen(a)); i++)
    {
        a1[j]=a[i];
        j++;
        a1[j]=char(srandom(1,255,a));
        j++;
    }
    strcpy(a,a1);
    a[(int(strlen(a))*2+1)]='\0';
}
void tdecrypt(char mess[255],char key[255])
{
    for(int i=(strlen(key)-1); i>=0; i--)
    {
        if(key[i]=='1')decrypt1(mess);
        if(key[i]=='2')decrypt2(mess);
        if(key[i]=='3')decrypt3(mess,key);
        if(key[i]=='4')decrypt4(mess);
    }
}
void tencrypt(char mess[255],char key[255])
{
    int longness=strlen(key);
    for(int i=0; i<longness; i++)
    {
        if(key[i]=='1')encrypt1(mess);
        if(key[i]=='2')encrypt2(mess);
        if(key[i]=='3')encrypt3(mess,key);
        if(key[i]=='4')encrypt4(mess);
    }
}
void sortme(char v[255])
{
    int n=strlen(v);
    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            if(v[i]>v[j])
                swap(v[i],v[j]);
    encrypt1(v);
}
bool isValidName(char word[255])
{
    for(int i=0; i<int(strlen(word)); i++)
    {
        if ((word[i] != ' ') && (!isalpha(word[i])))
        {
            return false;
        }
    }
    return true;
}
