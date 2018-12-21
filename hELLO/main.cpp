#include <iostream>
#include <thread>
#include <windows.h>
using namespace std;
void function1(){
    std::cout<<"Butt"<<std::endl;
}
int main()
{
    std::thread t1(function1);

    t1.detach();
    return 0;
}
