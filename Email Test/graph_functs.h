#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include "file_functs.h"
#include "math_functs.h"

using namespace std;

char FileExists(char name[255])
{
    ifstream dudu(name);
    if (dudu)
        return 1;
    return 0;
}

string getpasswords( const string& prompt = ":" )
  {
  string result;

  // Set the console mode to no-echo, not-line-buffered input
  DWORD mode, count;
  HANDLE ih = GetStdHandle( STD_INPUT_HANDLE  );
  HANDLE oh = GetStdHandle( STD_OUTPUT_HANDLE );
  SetConsoleMode( ih, mode & ~(ENABLE_ECHO_INPUT | ENABLE_LINE_INPUT) );
  WriteConsoleA( oh, prompt.c_str(), prompt.length(), &count, NULL );
  char c;
  while (ReadConsoleA( ih, &c, 1, &count, NULL) && (c != '\r') && (c != '\n'))
    {
    if (c == '\b')
      {
      if (result.length())
        {
        WriteConsoleA( oh, "\b \b", 3, &count, NULL );
        result.erase( result.end() -1 );
        }
      }
    else
      {
      WriteConsoleA( oh, "*", 1, &count, NULL );
      result.push_back( c );
      }
    }

  // Restore the console mode
  SetConsoleMode( ih, mode );
char a[255];
int i = 0;
while(i<result.length())
{
    a[i]=result[i];
i++;
}
return a;
  }

//returns the current attributes
WORD GetConsoleTextAttribute (HANDLE hCon)
{
  CONSOLE_SCREEN_BUFFER_INFO con_info;
  GetConsoleScreenBufferInfo(hCon, &con_info);
  return con_info.wAttributes;
}


  HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
  const int saved_colors = GetConsoleTextAttribute(hConsole);

int BeginScreen()
{
        int x=0;
    while(2)
    {
        system("cls");
        if(x==0)
        {
            cout<<"";
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_INTENSITY);
            cout<<"LOGIN"<<endl;
            SetConsoleTextAttribute(hConsole, saved_colors);
            cout<<"REGISTER"<<endl;
        }
        if(x==1)
        {
            SetConsoleTextAttribute(hConsole, saved_colors);
            cout<<"LOGIN"<<endl;
            SetConsoleTextAttribute(hConsole, FOREGROUND_RED | BACKGROUND_INTENSITY);
            cout<<"REGISTER"<<endl;
            SetConsoleTextAttribute(hConsole, saved_colors);
        }
        int a = getch();
        if(a==80 && x==0)
        {
            x++;
        }
        if(a==72 && x==1)
        {
            x--;
        }
        if(a==13)
        {
        break;
        }
    }
    return x;
}
int RegisterScreen(string &user,string &pass)
{
    string user1,pass1;
cout<<"Register \n\n";
cout<<"Username:";cin>>user1;
cout<<"Password";pass1=getpasswords();
user=user1;
pass=pass1;
}
int LoginScreen(string &user,string &pass)
{
    string user1,pass1;
cout<<"Login \n\n";
cout<<"Username:";cin>>user1;
cout<<"Password";pass1=getpasswords();
user=user1;
pass=pass1;
}
