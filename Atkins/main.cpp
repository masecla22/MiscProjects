#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;
long long SieveOfAtkin2(long long limit)
{
    int contor=0;
    vector<bool>sieve;
    sieve.resize(limit+5);
    for (long long i=0;i<limit;i++)
        sieve[i]=false;
    for (long long x=1;x*x<limit;x++) {
        for (long long y=1;y*y<limit;y++) {
            long long n=(4*x*x)+(y*y);
            if (n <= limit&&(n%12==1||n%12==5)){
                bool ff = sieve.at(n);
                ff ^= true;
                sieve.at(n)=ff;
            }
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7){
                bool ff = sieve.at(n);
                ff ^= true;
                sieve.at(n)=ff;
            }

            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11){
                bool ff = sieve.at(n);
                ff ^= true;
                sieve.at(n)=ff;
            }
        }
    }
    for (long long r = 5; r * r < limit; r++) {
        if (sieve.at(r)) {
            for (long long i = r * r; i < limit; i += r * r)
                sieve.at(i) = false;
        }
    }
    for (long long a = 5; a < limit; a++)
        if (sieve[a])
            contor++;
    return contor;
}
long long SieveOfAtkin(long long limit)
{
    if (limit > 2)
        cout << 2 << " ";
    if (limit > 3)
        cout << 3 << " ";
    vector<bool>sieve;
    sieve.resize(limit+5);
    for (long long i = 0; i < limit; i++)
        sieve[i] = false;
    for (long long x = 1; x * x < limit; x++) {
        for (long long y = 1; y * y < limit; y++) {
            long long n = (4 * x * x) + (y * y);
            if (n <= limit && (n % 12 == 1 || n % 12 == 5)){
                bool ff = sieve.at(n);
                ff ^= true;
                sieve.at(n)=ff;
            }
            n = (3 * x * x) + (y * y);
            if (n <= limit && n % 12 == 7){
                bool ff = sieve.at(n);
                ff ^= true;
                sieve.at(n)=ff;
            }

            n = (3 * x * x) - (y * y);
            if (x > y && n <= limit && n % 12 == 11){
                bool ff = sieve.at(n);
                ff ^= true;
                sieve.at(n)=ff;
            }
        }
    }
    for (long long r=5;r*r<limit;r++) {
        if (sieve.at(r)) {
            for (long long i=r*r;i<limit;i+=r*r)
                sieve.at(i) = false;
        }
    }
    for (long long a=5;a<limit;a++)
        if (sieve[a])
            cout << a << " "<<endl;
}
int main()
{
    cout<<LONG_LONG_MAX<<endl;
    cout << "Insert gayness level (pana la cat)" << endl;
    long long n=10000000;
    cin>>n;
    cout<<"Should I display my numbers or just how many? (1 for display 2 for howmany 0 for succ)"<<endl;
    long long opt = 2;
    cin>>opt;
    if(opt==0) while(true) cout<<"Whoms't eat dickn't?"<<endl;
    else if(opt==1) SieveOfAtkin(n);
    else if(opt==2) cout<<"Primes: "<<SieveOfAtkin2(n)<<" / "<<n<<endl;
    system("pause");
    return 0;
}
