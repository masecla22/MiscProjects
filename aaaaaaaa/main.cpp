#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include <iomanip>

using namespace std;
    std::random_device dev;
    std::mt19937 rng(dev());
int random(int min, int max)
{
    std::uniform_int_distribution<std::mt19937::result_type> dist6(min,max);
    return dist6(rng);
}
std::vector<int> raspunsuri;
int main()
{
    for(int i=0;i<50;i++)
    {
        int a = random(1,1000000);
        int b = random(1,1000000);
        if(b>a)
        {
            i--;
            continue;
        }
        cout<<a<<" - "<<setw(6)<<b<<" = "<<endl;
        raspunsuri.push_back(a-b);
    }

    for(int i=0;i<5;i++)
        cout<<"\n";
    for(int i=0;i<raspunsuri.size();i++){
        if(i%3==0)
            cout<<endl;
        cout<<raspunsuri.at(i)<<" ";
    }
    return 0;
}
