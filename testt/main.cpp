#include <iostream>

using namespace std;

int main()
{
    //104 116 116 112 115 58 47 47 112 97 115 116 101 98 105 110 46 99 111 109 47 67 120 75 57 114 57 114 55 32
    std::string a = "";
    int c=0;
    while(c!=-1)
    {
        cin>>c;
        char s = c;
        a+=s;
    }
    cout<<a;
    return 0;
}
