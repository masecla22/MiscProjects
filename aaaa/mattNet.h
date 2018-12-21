#include <iostream>
#include <fstream>
#include <windows.h>

using namespace std;

ofstream fout("url.data");
int lines(char name[255])
{int number_of_lines = 0;string line;
ifstream myfile(name);while (std::getline(myfile, line))
++number_of_lines;return number_of_lines;}
int getSource(char a[255])
{fout<<a;Sleep(100);system("start getURL.exe");}
