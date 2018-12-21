#include <windows.h>
#include <shlwapi.h>
#include <stdio.h>
#include <iostream>
#include <cstring>

using namespace std;
#if defined (_MSC_VER)
#pragma comment(lib, "shlwapi.lib")
#elif defined (__LCC__)
#pragma lib<shlwapi.lib>
#endif

#define ARRAY_SIZE(arr) (sizeof(arr)/sizeof((arr)[0]))

int main()
{
HKEY hKey;
LPCTSTR lpSubKey = ("http\\shell\\open\\command");
RegOpenKeyEx(HKEY_CLASSES_ROOT, lpSubKey, 0L, KEY_ALL_ACCESS, &hKey);
char szValue[256];
DWORD dwSize = 256;
RegQueryValueEx(hKey, NULL, NULL, NULL, (LPBYTE)szValue, &dwSize);
cout<<szValue<<endl;
system("cls");
if(strstr(szValue,"Mozi")!=0){cout<<"Possible mozilla";
}else if(strstr(szValue,"Chr")){cout<<"Possible chrome";}
else{cout<<"No idea"<<endl;}
    return 0;
}
