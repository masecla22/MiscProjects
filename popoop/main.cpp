#include <windows.h>
#include <iostream>

using namespace std;
BOOL EnableCloseButton(const HWND hwnd, const BOOL bState)
{
    HMENU   hMenu;
    UINT    dwExtra;

    if (hwnd == NULL) return FALSE;
    if ((hMenu = GetSystemMenu(hwnd, FALSE)) == NULL) return FALSE;
    dwExtra = bState ? MF_ENABLED : (MF_DISABLED | MF_GRAYED);
    return EnableMenuItem(hMenu, SC_CLOSE, MF_BYCOMMAND | dwExtra) != -1;
}
   HWND GetConsoleHwnd(void)
   {
       #define MY_BUFSIZE 1024 // Buffer size for console window titles.
       HWND hwndFound;         // This is what is returned to the caller.
       char pszNewWindowTitle[MY_BUFSIZE]; // Contains fabricated
                                           // WindowTitle.
       char pszOldWindowTitle[MY_BUFSIZE]; // Contains original
                                           // WindowTitle.

       // Fetch current window title.

       GetConsoleTitle(pszOldWindowTitle, MY_BUFSIZE);

       // Format a "unique" NewWindowTitle.

       wsprintf(pszNewWindowTitle,"%d/%d",
                   GetTickCount(),
                   GetCurrentProcessId());

       // Change current window title.

       SetConsoleTitle(pszNewWindowTitle);

       // Ensure window title has been updated.

       Sleep(40);

       // Look for NewWindowTitle.

       hwndFound=FindWindow(NULL, pszNewWindowTitle);

       // Restore original window title.

       SetConsoleTitle(pszOldWindowTitle);

       return(hwndFound);
   }
int main(int argc, _TCHAR* argv[])
{
    Sleep(1000);
    EnableCloseButton(GetConsoleHwnd(),false);
    return 0;
}
