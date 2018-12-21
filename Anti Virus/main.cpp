#include <iostream>
#include <fstream>
#include <cstring>
#include <windows.h>

using namespace std;
bool isfile(const char *fileName)
{
    std::ifstream infile(fileName);
    return infile.good();
}
char write(char a[255],int speed=50)
{
    int i=0;
    while(i<strlen(a))
    {
        cout<<a[i];
        Sleep(speed);
        i++;
    }
}
int main()
{
   write("Hello user, i am your antivirus...\n",20);
   Sleep(3000);
   write("Allow me to scan for some malicious files...\n",20);
   Sleep(3000);
   write("Total viruses found: 0\nCongratulations!\nYou have a safe computer\nRunning some extra tests...\nTrojan detection: 0\nOther spies: 0",20);
   write("\nUsing unconventional methods...\nNothing found...",20);
   Sleep(4000);
   system("color c");
   write("\nPossible malicious file found!\nDeleting it...",20);
   Sleep(4000);
   system("color a");
   write("\nVirus deleted succesfully",20);
      Sleep(4000);
   system("color c");
   write("\nPossible malicious file found!\nDeleting it...",20);
   Sleep(4000);
   system("color a");
    return 0;
}
