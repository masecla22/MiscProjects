#include <iostream>
#include <cmath>
#include <windows.h>

using namespace std;



bool prim(int num){
    if(num%2==0)
        return false;
    for(int i=3;i<sqrt(num);i+=2)
        if(num%i==0)
            return false;
    return true;
}




int sumcif(int num){
    int cont=0;
    while(num!=0)
    {
        cont+=num%10;
        num/=10;
    }
    return cont;
}


int main()
{
    for(int i=0;1;i++)
    {
        if(prim(i))
            cout<<i<<endl;
    }






    return 0;
}
