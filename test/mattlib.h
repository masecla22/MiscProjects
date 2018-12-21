#include <iostream>
#include <cmath>

using namespace std;
int pcheck(int a)
{
    int b;
    b=2;
    while(a>b)
    {
        if(a%b==0)
        {
            return 0;
            b=a+1;
        }
        else
        {
            b++;
        }
    }
    if(b==a)
    {
        return 1;
    }
}


void NrWc_pcheck(int a)
{
    int b;
    b=2;
    while(a>b)
    {
        if(a%b==0)
        {
            cout<<"Not prime"<<endl;
            b=a+1;
        }
        else
        {
            b++;
        }
    }
    if(b==a)
    {
        cout<<"Prime"<<endl;
    }
}
///Next function
int WrNc_pcheck(int a)
{
    int b;
    b=2;
    while(a>b)
    {
        if(a%b==0)
        {
            return 0;
            b=a+1;
        }
        else
        {
            b++;
        }
    }
    if(b==a)
    {
        return 1;
    }
}
///Next function
int WrWc_pcheck(int a)
{
    int b;
    b=2;
    while(a>b)
    {
        if(a%b==0)
        {
            cout<<"Not prime"<<endl;
            return 0;
            b=a+1;
        }
        else
        {
            b++;
        }
    }
    if(b==a)
    {
        cout<<"Prime"<<endl;
        return 1;
    }
}
///Next function






void succ(int a)
{
    cout<<a+1<<endl;
}
int WrNc_succ(int a)
{
    return a+1;
}
void NrWc_succ(int a)
{
    cout<<a+1<<endl;
}
int WrWc_succ(int a)
{
    cout<<a+1<<endl;
    return a+1;
}


void pred(int a)
{
    cout<<a-1<<endl;
}
int WrNc_pred(int a)
{
    return a-1;
}
void NrWc_pred(int a)
{
    cout<<a-1<<endl;
}


int WrWc_pred(int a)
{
    cout<<a-1<<endl;
    return a-1;
}
///prednsucc function

void prednsucc(int a)
{
    pred(a);
    succ(a);

}
///tillto function
void tillto(int a)
{
    int b=1;
    while(b<=a)
    {
        cout<<b<<endl;
        b++;
    }
}
///fromtotillto function
void fromtotillto(int from,int till)
{
    while(from<=till)
    {
        cout<<from<<endl;
        from++;
    }
}
///fromto function
void fromto(int a)
{
    int b=0;
    while(2)
    {
        cout<<a+b<<endl;
        b++;
    }
}
///gsum function

void gsum(int a)
{
    int b;
    b=(a*(a+1))/2;
    cout<<b<<endl;
}
int WrNc_gsum(int a)
{
    int b;
    b=(a*(a+1))/2;
    return b;
}
void NrWc_gsum(int a)
{
    int b;
    b=(a*(a+1))/2;
    cout<<b<<endl;
}

int WrWc_gsum(int a)
{
    int b;
    b=(a*(a+1))/2;
    cout<<b<<endl;
    return b;
}
///sun function
void sum(int a, int b)
{
    cout<<a+b<<endl;
}
int WrNc_sum(int a, int b)
{
    return a+b;
}
void NrWc_sum(int a, int b)
{
    cout<<a+b<<endl;
}
int WrWc_sum(int a, int b)
{
    cout<<a+b<<endl;
    return a+b;
}
///subt function
void subt(int a, int b)
{
    cout<<a-b<<endl;
}
int WrNc_subt(int a, int b)
{
    return a-b;
}
void NrWc_subt(int a, int b)
{
    cout<<a-b<<endl;
}
int WcWr_subt(int a, int b)
{
    cout<<a-b<<endl;
    return a-b;
}
void multpl(int a, int b)
{
    cout<<a*b<<endl;
}
int WrNc_multpl(int a, int b)
{
    return a*b;
}
void NrWc_multpl(int a, int b)
{
    cout<<a*b<<endl;
}
int WrWc_multpl(int a, int b)
{
    cout<<a*b<<endl;
    return a*b;
}
///mod function
void mod(int a, int b)
{
    cout<<a%b<<endl;
}
int WrNc_mod(int a, int b)
{
    return a%b;
}
void NrWc_mod(int a, int b)
{
    cout<<a%b<<endl;
}
int WrWc_mod(int a, int b)
{
    cout<<a%b<<endl;
    return a%b;
}
///div function
void divs(int a, int b)
{
    cout<<a/b<<endl;
}
int WrNc_divs(int a, int b)
{
    return a/b;
}
void NrWc_divs(int a, int b)
{
    cout<<a/b<<endl;
}
int WrWc_divs(int a, int b)
{
    cout<<a/b<<endl;
    return a/b;
}
void exdiv(double a, double b)
{
    cout<<a/b<<endl;
}
int WrNc_exdiv(double a, double b)
{
    return a/b;
}
void NrWc_exdiv(double a, double b)
{
    cout<<a/b<<endl;
}
int WrWc_exdiv(double a, double b)
{
    cout<<a/b<<endl;
    return a/b;
}
void console_log(char a[250])
{
    cout<<a<<endl;
}


void cmmdc(int a,int b)
{
    while (a!=b)
    {
        if(a>b)
        {
            a-=b;
        }
        if(a<b)
        {
            b-=a;
        }
    }
    cout<<a<<endl;
}
int WrNc_cmmdc(int a,int b)
{
    while (a!=b)
    {
        if(a>b)
        {
            a-=b;
        }
        if(a<b)
        {
            b-=a;
        }
    }
   return a;
}
void NrWc_cmmdc(int a,int b)
{
    while (a!=b)
    {
        if(a>b)
        {
            a-=b;
        }
        if(a<b)
        {
            b-=a;
        }
    }
    cout<<a<<endl;
}
int WrWc_cmmdc(int a,int b)
{
    while (a!=b)
    {
        if(a>b)
        {
            a-=b;
        }
        if(a<b)
        {
            b-=a;
        }
    }
    cout<<a<<endl;
    return a;
}
void cmmmc(int a,int b)
{
    int x,y;
    x=a;
    y=b;
    while (a!=b)
    {
        if(a>b)
        {
            a-=b;
      }
        if(a<b)
        {
            b-=a;
        }
    }
    int z;
    z=a;
    a=x;
    b=y;
    cout<<(a*b)/z<<endl;

}
int WrNc_cmmmc(int a,int b)
{
    int x,y, lv;
    x=a;
    y=b;
    while (a!=b)
    {
        if(a>b)
        {
            a-=b;
        }
        if(a<b)
        {
            b-=a;
        }
    }
    int z;
    z=a;
    a=x;
    b=y;
    lv=(a*b)/z;
    return lv;

}
void NrWc_cmmmc(int a,int b)
{
    int x,y;
    x=a;
    y=b;
    while (a!=b)
    {
        if(a>b)
        {
            a-=b;
        }
        if(a<b)
        {
            b-=a;
        }
    }
    int z;
    z=a;
    a=x;
    b=y;
    cout<<(a*b)/z<<endl;

}
int WrWc_cmmmc(int a,int b)
{
    int x,y, lv;
    x=a;
    y=b;
    while (a!=b)
    {
        if(a>b)
        {
            a-=b;
        }
        if(a<b)
        {
            b-=a;
        }
    }
    int z;
    z=a;
    a=x;
    b=y;
    lv=(a*b)/z;
    cout<<(a*b)/z<<endl;
    return lv;

}
void pow(int a,int b)
{
    double wv=1, c;
    c=a;
    while(wv<b)

    {
        a*=c;
        wv+=1;
    }
    cout<<a<<endl;
}
int WrNc_pow(int a,int b)
{
    double wv=1, c;
    c=a;
    while(wv<b)

    {
        a*=c;
        wv+=1;
    }
    return a;
}
void NrWc_pow(int a,int b)
{
    double wv=1, c;
    c=a;
    while(wv<b)

    {
        a*=c;
        wv+=1;
    }
    cout<<a<<endl;
}
int WrWc_pow(int a,int b)
{
    double wv=1, c;
    c=a;
    while(wv<b)

    {
        a*=c;
        wv+=1;
    }
    cout<<a<<endl;
}

void sqr(int a)
{
    double c;
    c=pow(a,0.5);
    cout<<c<<endl;
}
int WrNc_sqr(int a)
{
    double c;
    c=pow(a,0.5);
    return c;
}
void NrWc_sqr(int a)
{
    double c;
    c=pow(a,0.5);
    cout<<c<<endl;
}
double WrWc_sqr(int a)
{
    double c;
    c=pow(a,0.5);
    cout<<c<<endl;
    return c;
}
void oppnum(int a)
{
    cout<<a*(-1)<<endl;
}
int WrNc_oppnum(int a)
{
    return a*(-1);
}
int WrWc_oppnum(int a)
{
    cout<<a*(-1)<<endl;
    return a*(-1);
}
void issmaller(int a,int b)
{
    if(a>b)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
}
void NrWc_issmaller(int a,int b)
{
    if(a>b)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
}
int WrNc_issmaller(int a,int b)
{
    if(a>b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int WrWc_issmaller(int a,int b)
{
    if(a>b)
    {
        cout<<1;
        return 1;
    }
    else
    {
        cout<<0;
        return 0;
    }
}


void isbigger(int a,int b)
{
    if(a<b)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
}
void NrWc_isbigger(int a,int b)
{
    if(a<b)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
}
int WrNc_isbigger(int a,int b)
{
    if(a<b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int WrWc_isbigger(int a,int b)
{
    if(a<b)
    {
        cout<<1;
        return 1;
    }
    else
    {
        cout<<0;
        return 0;
    }
}


void isequal(int a,int b)
{
    if(a==b)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
}
void NrWc_isequal(int a,int b)
{
    if(a==b)
    {
        cout<<1;
    }
    else
    {
        cout<<0;
    }
}
int WrNc_isequal(int a,int b)
{
    if(a==b)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int WrWc_isequal(int a,int b)
{
    if(a==b)
    {
        cout<<1;
        return 1;
    }
    else
    {
        cout<<0;
        return 0;
    }
}


