#include <windows.h>
#include <iostream>
using namespace std;
int color(string color)
{
    string colss="FOREGROUND_";
    colss= colss+color;
    char a[255];
    ;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colss);

}

int main()
{

	color("GREEN");
	cout<<"green";
	color("RED");
	cout<<"red";
	return 0;
}
