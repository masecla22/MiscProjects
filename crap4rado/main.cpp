#include <iostream>
#include <string.h>
#include <windows.h>

using namespace std;

int main()
{
  char a[255];
  cout<<"What is the message you want to DECRYPT?"<<endl;
  cin.getline(a,255);
  for(int i=0;i<strlen(a);i++)if(isupper(a[i]))cout<<a[i];
cout<<"\nThanks for using my tool!"<<endl;
system("PAUSE");
}
