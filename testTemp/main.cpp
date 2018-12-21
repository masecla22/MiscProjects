#include <iostream>

using namespace std;
template<typename AL>reverse(AL thing)
{
    if(is_same<AL,int>::thing)
    {
        cout<<"INT"<<endl;
    }
    if(is_same<AL,string>::thing)
    {
        cout<<"STRING"<<endl;
    }
}
int main()
{
    reverse<string>("5");
    return 0;
}
