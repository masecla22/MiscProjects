#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>
#include <cstdio>
#include <vector>
#include <mattgui.h>
using namespace std;
long long isPrime(long long a)
{
    for(long long i=2; i<a; i++)
        if(a%i==0)
            return 0;
    return 1;
}
long long isPrimeV2(long long a)
{
    if(a%2==0)return 0;
    for(long long i=1; i<a; i+=2)
        if(a%i==0&&i!=1)
            return 0;
    return 1;
}
long long isPrimeV3(long long a)
{
    if(a%2==0)return 0;
    for(long long i=1; i<sqrt(a); i+=2)
        if(a%i==0&&i!=1)
            return 0;
    return 1;
}
unsigned long long findSieveSize(unsigned long long n)
{
    if (n < 6)return 13;
    if (n >= (~0UL / log(~0UL)))return 0;
    unsigned long long low  = n;
    unsigned long long high = ~0UL - 1;
    do
    {
        unsigned long long mid   = low + (high - low) / 2;
        double guess = mid / log(mid);
        if (guess > n)high = (unsigned long long) mid - 1;
        else low = (unsigned long long) mid + 1;
    }
    while (low < high);
    return high + 1;
}

unsigned long long prime(unsigned long long n)
{
    if (!n) return 1;
    if (!--n) return 2;
    unsigned long long sieveSize = findSieveSize(n);
    unsigned long long count     = 0;
    unsigned long long max_i     = sqrt(sieveSize-1)+1;
    if (sieveSize == 0)
        return 0;
    vector<bool> sieve(sieveSize);
    for (unsigned long long i = 3;  true;  i += 2)
    {
        if (!sieve[i])
        {
            if (++count == n)return i;
            if (i >= max_i)continue;
            unsigned long long j    = i*i;
            unsigned long long inc  = i+i;
            unsigned long long maxj = sieveSize - inc;
            do
            {
                sieve[j] = true;
                if (j >= maxj)break;
                j += inc;
            }
            while (1);
        }
    }
    return 0;
}

int main()
{
    long long a=gui("Algorithm 1/Algorithm 2/Algorithm 3/Algorithm 4/Algorithm 5  \n\nTOOLS\n/Bit Finder/");
    if(a==0)
    {
        system("cls");
        long long a;
        cin>>a;
        long long times,timed;
        times=clock();
        for(long long i=2; i<a; i++)
        {
            long long s=prime(i);
            if(s>a)
            {
                cout<<"NOT FOUND."<<endl;
                break;
            }
            cout<<"Testing: "<<s<<endl;
            if(a%s==0)
                if(isPrime(a/s))
                {
                    timed=clock();
                    times=timed-times;
                    cout<<"FOUND! "<<s<<"   "<<a/s<<"   Took: "<<times<<"/ticks"<<endl;
                    return 0;
                }
        }
    }
    if(a==1)
    {
        system("cls");
        long long a;
        cin>>a;
        long long times,timed;
        times=clock();
        for(long long i=3; i<a; i+=2)
        {
            long long s=prime(i);
            if(s>a)
            {
                cout<<"NOT FOUND."<<endl;
                break;
            }
            cout<<"Testing: "<<s<<endl;
            if(a%s==0)
                if(isPrimeV2(a/s))
                {
                    timed=clock();
                    times=timed-times;
                    cout<<"FOUND! "<<s<<"   "<<a/s<<"   Took: "<<times<<"/ticks"<<endl;
                    return 0;
                }
        }
    }
    if(a==2)
    {
        system("cls");
        long long a;
        cin>>a;
        long long times,timed;
        times=clock();
        for(long long i=3; i<sqrt(a); i+=2)
        {
            long long s=prime(i);
            if(s>a)
            {
                cout<<"NOT FOUND."<<endl;
                break;
            }
            cout<<"Testing: "<<s<<endl;
            if(a%s==0)
                if(isPrimeV3(a/s))
                {
                    timed=clock();
                    times=timed-times;
                    cout<<"FOUND! "<<s<<"   "<<a/s<<"   Took: "<<times<<"/ticks"<<endl;
                    return 0;
                }
        }
    }
    if(a==3)
    {
        system("cls");
        cout<<"Sadly this algorithm is too powerful. It's around 10 times faster than the first algorithm. Sadly you can't use it\n unless you have a pass."<<endl;
        long long times,timed,prev=1,a,pass;
        cout<<"PASS: ";
        while(pass!=2003)
            cin>>pass;
        system("cls");
        cout<<"NUMBER: ";
        cin>>a;
        times=clock();
        for(long long i=2; i<sqrt(a); i++)
        {
            if(i/10000!=prev)
            {
                cout<<i<<"/"<<int(sqrt(a))<<endl;
                prev=i/10000;
            }
            long long s=prime(i);
            if(s>a)
            {
                cout<<"NOT FOUND."<<endl;
                break;
            }
            if(a%s==0)
                if(isPrimeV3(a/s))
                {
                    timed=clock();
                    times=timed-times;
                    cout<<"FOUND! "<<s<<"   "<<a/s<<"   Took: "<<times<<"/ticks"<<endl;
                    return 0;
                }
        }
    }
    if(a==4)
    {
        system("cls");
        cout<<"Sadly this algorithm is too powerful. It's around 10 times faster than the first algorithm. Sadly you can't use it\n unless you have a pass."<<endl;
        long long pass,a;
        cout<<"PASS: ";
        while(pass!=2003)
            cin>>pass;
        system("cls");
        cout<<"NUMBER: ";
        cin>>a;
        cout<<"ETA: "<<sqrt(a)/4<<" ticks or "<<int(sqrt(a)/400)<<" seconds "<<int(sqrt(a)/400)/60<<" minutes"<<endl;
        long long times,timed;
        times=clock();
        int prev=1,prev1=0;
        if(float(float(sqrt(a))-int(sqrt(a)))!=0)
            for(long long i=2; i<sqrt(a); i++)
            {
                int perc=(100*i)/int(sqrt(a));
                if(prev1!=perc)
                {
                    cout<<perc<<"%    \r";
                    prev1=perc;
                }
                long long s=prime(i);
                if(s>a)//4
                {
                    cout<<"NOT FOUND."<<endl;
                    break;
                }
                if(a%s==0)
                    if(isPrimeV3(a/s))
                    {
                        timed=clock();
                        times=timed-times;
                        cout<<"FOUND! "<<s<<"   "<<a/s<<"   Took: "<<times<<"/ticks"<<endl;
                        return 0;
                    }
            }
        else
        {
            timed=clock();
            times=timed-times;
            cout<<"FOUND! "<<sqrt(a)<<"   "<<sqrt(a)<<"   Took: "<<times<<"/ticks"<<endl;
            return 0;
        }
    }
    if(a==5)
    {
        long long a=1,s;
        cin>>s;
        while(pow(2,a)<s)
            a++;
        cout<<a<<"   "<<endl;
    }
}
