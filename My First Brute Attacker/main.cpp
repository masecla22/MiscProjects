#include <iostream>

using namespace std;
char perm[255];
strcpy(perm,"")
char isper(char a)
{
    int i=0;
    while(i<strlen(perm))
    {
        if(a==perm[i])
            return 1;
        i++;
    }
    return 0;
}
char conv(char &a)
{

}
int main()
{
    int a=0,b=0,c=0,d=0;
    while(2)
    {
        cout<<char(a)<<char(b)<<char(c)<<char(d)<<"         "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
        if(b==255)
        {
            a++;
            b=0;
        }
        if(c==255)
        {
            b++;
            c=0;
        }
        if(d==255)
        {
            c++;
            d=0;
        }
        d++;
    }
    return 0;
}
