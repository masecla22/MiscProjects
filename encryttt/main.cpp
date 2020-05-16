#include <iostream>
#include <cstring>
#include <cmath>
#include <ctime>
#include "nfunctions.h"

using namespace std;
void nextKey(char a[255])
{
    up(a[(strlen(a)-1)]);
    for(int i=(strlen(a)-1); i>=0; i--)
    {
        if(tochar(a[i])==howmany && i!=0)
        {
            up(a[(i-1)]);
            //cout<<"morphed "<<i<<"in 1"<<endl;
            a[i]='1';
        }
    }
}

int main()
{
    int skp=1;
    int homany=gethowmany();
    char option[10];
    cout<<"Encrypt or Decrypt?\nPROTIP: Instead of typing encrypt you can type E or alternatively D"<<"\n";
    cin>>option;
    if(option[0]=='E' || option[0]=='e')
    {
        cls;
        if(skp==0)
        {
            loading("modules");
            loading("encryptions");
            Sleep(3000);
        }
        cls;
        cout<<"Type a message to encrypt please: ";
        char mess[255],key[255];
        cin.get();
        cin.getline(mess,255);
        cout<<"Type a key to use in encryption (you can type auto to generate one automatically): ";
        cin>>key;
        int longness;
        if(strcmp(key,"auto")==0)
        {
            cout<<"How long should the key be (the bigger it is, the longer it takes to generate, but its harder to decrypt): ";
            cin>>longness;
            char key1[255];
            srand(time(NULL));
            autogen(key1,longness);
            strcpy(key,key1);
        }
        else longness=strlen(key);
        for(int i=0; i<longness; i++)
        {
            if(key[i]=='1')encrypt1(mess);
            if(key[i]=='2')encrypt2(mess);
            if(key[i]=='3')encrypt3(mess,key);
            if(key[i]=='4')encrypt4(mess);
        }
        cout<<"Your encrypted message: "<<mess<<"\n";
        cout<<"Your key: "<<key<<"\n";
    }
    if(option[0]=='d'||option[0]=='D')
    {
        cls;
        if(skp==0)
        {
            loading("modules");
            loading("encryptions");
            Sleep(3000);
        }
        cls;
        cout<<"Type a message to decrypt please: ";
        char mess[255];
        cin.get();
        cin.getline(mess,255);
        cout<<"Type the key you got when generated this message: ";
        char key[255];
        cin>>key;
        tdecrypt(mess,key);
        cout<<"Your encrypted message: "<<mess<<"\n";
        encrypt1(key);
        cout<<"Your key: "<<key<<"\n";
    }
    if(option[0]=='k'||option[0]=='K')
    {
        cls;
        system("title BRUTE FORCE ACTIVATED");
        system("color c");
        cout<<"Brute force mode. Please enter the password: ";
        char pass[255];
        cin>>pass;
        if(strcmp(pass,"mattiamatei2303")==0)
        {
            system("color a");
            cout<<"ACCESS GRANTED. ACTIVATING...";
            Sleep(1500);
            cls;
            system("color c");
            cout<<"Enter your encrypted shit: ";
            char tbf[255];
            cin.getline(tbf,255);
            cout<<"How long do you think the key could be (most of them are up to 10): ";
            char lenght[200];
            cin>>lenght;

        }
    }
    /**
    char a[255];
    cin>>a;
    for(int i=0;i<30;i++)
    {
    nextKey(a);
    cout<<a<<endl;
    }
    */
    return 0;
}
