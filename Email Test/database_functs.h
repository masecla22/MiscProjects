#include <wininet.h>
#include <iostream>
#include <stdexcept>
#include <string>
#include <windows.h>
#include "file_functs.h"
using namespace std;

string getpassword( const string& prompt = ":" )
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
  char registers(char user[255],char pass[255])
{
    char FileNM[255];
    strcpy(FileNM,"Accs\\");
    strcat(FileNM,user);
    strcat(FileNM,".txt");
        ofstream fout(FileNM);
        fout<<pass;
        return 1;
        return 0;
}
char login(char user[255],char pass[255])
{
    char FileNM[255];
    strcpy(FileNM,"Accs\\");
    strcat(FileNM,user);
    strcat(FileNM,".txt");
    if(FileExists(FileNM)==1)
    {
        fstream file(FileNM, ios::in | ios::out | ios::app);
        char pass1[255];
        file>>pass1;
        if(strcmp(pass,pass1)==0)
        {
            return 1;
        }
        return 0;
    }
    else
        return 0;
}

