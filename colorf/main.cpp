/**
#include <iostream>
#include <windows.h>

using namespace std;

int main()
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hStdOut, FOREGROUND_RED | BACKGROUND_BLUE | BACKGROUND_GREEN | BACKGROUND_RED);
cout<<"Baiiii"<<endl;
    return 0;
}
*/
