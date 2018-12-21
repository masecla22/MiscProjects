#include <iostream>

using namespace std;
int apply(int &a)
{
    if(a%2==0)
    {
        a/=2;
        return 1;
    }
    else
    {
        a*=3;
        a++;
    }
}
int crsh(int a)
{
    while(a!=4||a!=1)
        apply(a);
    return 1;
}
int main()
{
    int many=1000000;
    int prev=0;
    for(int i=1;i<=many;i++)
    {
        crsh(i);
        int s=(i*100)/many;
        if(s!=prev)
        {
            prev=s;
            cout<<s<<"% \r";
        }
        //cout<<"VERIFIED "<<i<<endl;
    }
    return 0;
}
