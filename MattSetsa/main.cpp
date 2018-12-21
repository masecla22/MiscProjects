#include <iostream>
#include "mattsets.h"

using namespace std;

int main()
{
    option a;
    a = parseFromString("hello : wonderful");
    cout<<a.toString();
    return 0;
}
