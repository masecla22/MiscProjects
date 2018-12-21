#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    cout<<"Io ripeto!"<<endl;
    while(2){
    char a[255];
    cout<<"Tu: ";
    cin.getline(a,255);
    cout<<"Robot: ";
    int ok=0;
    if(stricmp(a,"ciao")==0)
    {
        ok=1;
        cout<<"Ciao!"<<endl;
    }
    if(stricmp(a,"sei bravo")==0)
    {
        ok=1;
        cout<<"Grazie!"<<endl;
    }
    if(stricmp(a,"come stai")==0)
    {
        ok=1;
        cout<<"Molto bene!"<<endl;
    }
    if(stricmp(a,"")==0)
    {
        ok=1;
        cout<<"Molto bene!"<<endl;
    }
    if(ok==0)
    {
        cout<<"Non so come rispondere a questo!"<<endl;
    }
    }
    return 0;
}

