#include <iostream>
#include <windows.h>
using namespace std;
int mod(int a)
{
    int j=a;
    j*=1-2*(j<0);
    return j;
}
int main()
{
    int nr=1000000;
 while(nr<10000000){
        if(nr%2==0)
        {
            cout<<"nr = "<<nr<<" and its EVEN"<<endl;
        }
        else
        {
            cout<<"nr = "<<nr<<" and its ODD"<<endl;
        }
        int nr1=nr;
        while(mod(nr1)!=0)
        {
            if(nr1%2==0)
            {
                cout<<"   nr /2= "<<nr1/2<<endl;
                nr1/=2;
                if(nr1/2==1)
                    break;
            }
            else
            {
                cout<<"   nr *3+1= "<<nr1*3+1<<endl;
                nr1*=3;
                nr1+=1;
                if(nr1*3+1==4)
                    break;
            }
        }
        nr++;
        if(nr%10000==0)
        {
            cout<<"Done "<<nr/10000<<"0000\r";
        }
}
    return 0;
}
