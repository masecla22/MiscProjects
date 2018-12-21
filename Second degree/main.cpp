#include <iostream>
#include <cmath>
using namespace std;
const char SQUARED=253;
int main()
{
    double a,b,c;
    cin>>a>>b>>c;
    cout<<"Is this your equation? Y or N"<<endl;
    if(a!=1 && a!=-1)
        cout<<a;
    if(a==-1)
        cout<<"-";
    cout<<"x"<<SQUARED;
    if(b>0)
        cout<<" + ";
    if(b!=1)
        if(b!=-1)
            cout<<b;
        else
            cout<<" - ";
    cout<<"x";
    if(c!=0)
        if(c<0)
            cout<<" - "<<c*(-1);
        else
            cout<<" + "<<c;
    cout<<" = 0"<<endl;
    char opt;
    cin>>opt;
    if(opt=='y'||opt=='Y')
    {
        if((b*b-4*a*c)<0)
        {
            cout<<"The variables are incorrect. The sqrt is negative!"<<endl;
        }
        else{
        double root1,root2;
        root1=((-1)*b+sqrt(b*b-4*a*c))/(2*a);
        root2=((-1)*b-sqrt(b*b-4*a*c))/(2*a);
        /// (x-root1)(x-root2);
        cout<<"(x";
        if(root1!=root2){
            if(root1<0)
                cout<<"+"<<(-1)*root1;
            else
                cout<<root1;
            cout<<")(x";
            if(root2<0)
                cout<<"+"<<(-1)*root2;
            else
                cout<<root2;
            cout<<")=0";
        }else {
            if(root1<0)
                cout<<"+"<<(-1)*root1;
            else
                cout<<root1;
            cout<<")"<<SQUARED<<" = 0"<<endl;

        }
        }
    }
    else
    {
        cout<<"Try again!"<<endl;
    }
    return 0;
}
