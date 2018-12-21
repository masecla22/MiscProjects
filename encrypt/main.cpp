#include "nfunctions.h"
#include <mattgui.h>
using namespace std;
/**
1.0 Added a simple encryption with the unability to decrypt
1.1 Added the ability to decrypt that thing
1.2 Added the nfunctions header with the random function inside
1.3 Added the next 3 encryption methods
1.4 Added a new menu based on capital letters
1.5 Added more functionality to nfunctions
1.6 Added a bruteforce attack method
1.7 After 3 rewrites of the entire bruteforce method i managed to get it to work
1.8 Did a LOT of code cleaning and compacted the source.(from 6697)
1.9 Modified the random generation of keys + Succesfully confirmed a bruteforce crack.
*/
int main()
{

    char f[255];
    int skp=1;
    int option=gui("Encrypt/Decrypt/Brute Force/zForce/");
    if(option==0)
    {
        cls;
        if(skp==0)
        {
            strcpy(f,"modules");
            loading(f);
            strcpy(f,"encryptions");
            loading(f);
            Sleep(3000);
        }
        cls;
        cout<<"Type a message to encrypt please: ";
        char mess[1000],key[1000];
        cin.get();
        cin.getline(mess,1000);
        cout<<"Type a key to use in encryption (you can type auto to generate one automatically): ";
        cin>>key;
        int longness;
        if(stricmp(key,"auto")==0)
        {
            cout<<"How long should the key be (the bigger it is, the longer it takes to generate, but its harder to decrypt): ";
            cin>>longness;
            char key1[1000];
            srand(time(NULL));
            autogen(key1,longness);
            strcpy(key,key1);
        }
        longness=strlen(key);
        tencrypt(mess,key);
        cout<<"Your encrypted message: "<<mess<<"\n";
        cout<<"Your key: "<<key<<"\n";
    }
    if(option==1)
    {
        cls;
        if(skp==0)
        {
            strcpy(f,"modules");
            loading(f);
            strcpy(f,"encryptions");
            loading(f);
            Sleep(3000);
        }
        cls;
        cout<<"Type a message to decrypt please: ";
        char mess[1000];
        cin.get();
        cin.getline(mess,1000);
        cout<<"Type the key you got when generated this message: ";
        char key[1000];
        cin>>key;
        tdecrypt(mess,key);
        cout<<"Your encrypted message: "<<mess<<"\n";
        encrypt1(key);
        cout<<"Your key: "<<key<<"\n";
    }
    if(option==2)
    {
        cls;
        system("title BRUTE FORCE ACTIVATED");
        system("color c");
        char pass[1000];
        if(skp!=1)
        {
            cout<<"Brute force mode. Please enter the password: ";
            cin>>pass;
        }
        if(strcmp(pass,"mattiamatei2303")==0 || skp==1)
        {
            system("color a");
            cout<<"ACCESS GRANTED. ACTIVATING...";
            Sleep(1500);
            cls;
            system("color c");
            cout<<"Enter your encrypted shit: ";
            char tbf[1000];
            cin.get();
            cin.getline(tbf,1000);
            cout<<"How long do you think the key could be (most of them are up to 10): ";
            int lenght;
            cin>>lenght;
            char key[1000];
            strcpy(key,"1");
            for(int j=1; j<=lenght; j++)
            {
                for(double i=0; i<pow(howmany,strlen(key)); i++)
                {
                    char mess[1000];
                    strcpy(mess,tbf);
                    tdecrypt(mess,key);
                    cout<<"Key: "<<key<<" did "<<mess<<endl;
                    nextKey(key);
                }
                setall(key,'1',(j+1));
            }
        }
    }
    if(option==3)
    {
        cout<<"Welcome user. To zForce. This feature is available to DEVS only."<<endl;
        system("color a");
        cout<<"ACCESS GRANTED. ACTIVATING...";
        Sleep(1500);
        cls;
        system("color c");
        cout<<"Enter your encrypted shit: ";
        char tbf[1000];
        cin.get();
        cin.getline(tbf,1000);
        cout<<"How long do you think the key could be (most of them are up to 10): ";
        int lenght;
        cin>>lenght;
        char key[1000];
        strcpy(key,"1");
        for(int j=1; j<=lenght; j++)
        {
            while(howmanyc(key,toint(howmany))!=j)
            {
                char mess[1000];
                strcpy(mess,tbf);
                tdecrypt(mess,key);
                cout<<"Key: "<<key<<" did "<<mess<<endl;
                nextSKey(key);
            }
            setall(key,'1',(j+1));
        }
    }
    return 0;
}
