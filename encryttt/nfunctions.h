#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <cmath>
#include <windows.h>
#include <ctime>
#define cls system("cls")
using namespace std;
int howmany=4;
int random(int min, int max) {
    return min + (rand() % static_cast<int>(max - min + 1));
}
int srandom(int min, int max,char a[255]) {
    return min + (rand() % static_cast<int>(max - min + 1))+strlen(a)+int(a[3]);
}
    void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        std::swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}
char* itoa(int num, char* str, int base)
{
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0 && base == 10)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9)? (rem-10) + 'a' : rem + '0';
        num = num/base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}
int toint(int a) {
    char f[2];
    itoa(a,f,10);
    return f[0];
}
int gethowmany() {
    return howmany;
}
char tochar(char a) {
    return int(a)-48;
}
int autogen(char a[255],int longness) {
    for(int i=0; i<longness; i++) {
        a[i]=toint(random(1,howmany));
    }
    a[longness]='\n';
}
void swt(char a[255],int pos1, int pos2) {
    char aux;
    aux = a[pos1];
    a[pos1]=a[pos2];
    a[pos2]=aux;
}
void loading(char a[255]) {
    for(int i=0; i<=100; i++) {
        cout<<"Loading "<<a<<" "<<i<<"%\r";
        Sleep((30+random(0,100)));
    }
    cout<<endl;
}
void cpyto(char a[255],char a1[255],int to) {
    for(int i=0; i<to; i++)
        a[i]=a1[i];
}
void up(char &a) {
    if(!(tochar(a)>=howmany))
        a++;
}
int isall(char a[255],int what) {
    for(int i=0; i<strlen(a); i++)
        if(!(a[i]==toint(what)))
            return 0;
    return 1;
}
void encrypt1(char a[255]) {
    for(int i=0; i<strlen(a)/2; i++) {
        char temp=a[i];
        a[i]=a[strlen(a)-i-1];
        a[strlen(a)-i-1]=temp;
    }
}
void encrypt2(char a[255]) {
    for(int i=0; i<strlen(a); i++)
        a[i]+=3;
}
void encrypt3(char a[255],char key[255]) {
    for(int i=0; i<strlen(a); i++)
        a[i]+=strlen(key);
}
void encrypt4(char a[255]) {
    for(int i=0; i<strlen(a)-1; i+=2)
        swt(a,i,(i+1));
}
void decrypt1(char a[255]) {
    encrypt1(a);
}
void decrypt2(char a[255]) {
    for(int i=0; i<strlen(a); i++)
        a[i]-=3;
}
void decrypt3(char a[255],char key[255]) {
    for(int i=0; i<strlen(a); i++)
        a[i]-=strlen(key);
}
void decrypt4(char a[255]) {
    encrypt4(a);
}
void encrypt5(char a[255]) {
    char a1[255];
    int j=0;
    for(int i=0; i<strlen(a); i++) {
        a1[j]=a[i];
        j++;
        a1[j]=char(srandom(1,255,a));
        j++;
    }
    strcpy(a,a1);
    a[(strlen(a)*2+1)]='\0';
}
void tdecrypt(char mess[255],char key[255]) {
    encrypt1(key);
    for(int i=0; i<strlen(key); i++) {
        if(key[i]=='1')
            decrypt1(mess);
        if(key[i]=='2')
            decrypt2(mess);
        if(key[i]=='3')
            decrypt3(mess,key);
        if(key[i]=='4')
            decrypt4(mess);
    }
}
