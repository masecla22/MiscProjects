#include <iostream>

using namespace std;

int main()
{
    string a;
    while(2)
    {
        cin>>a;
        int ok=0;
        if(a=="Ping" || a=="ping")
        {
            cout<<"Pong"<<endl;
            ok=1;
        }
        if(a=="Pong" || a=="pong")
        {
            cout<<"Ping"<<endl;
            ok=1;
        }
        if(ok==0)
        {
            cout<<"y u do dis."<<endl;
        }

    }
    return 0;
}
