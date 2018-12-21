#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> fibo;
    fibo.push_back(1);
    fibo.push_back(1);
    int n;
    cin>>n;
    for(int i=2;fibo.at(i-1)<n;i++)
        fibo.push_back(fibo.at(i-1)+fibo.at(i-2));
    for(int i=0;i<fibo.size()-1;i++)
        cout<<fibo.at(i)<<" ";

    return 0;
}
