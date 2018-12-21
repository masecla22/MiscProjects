#include <Windows.h>

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

// WinMain: The Application Entry Point
int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR nCmdLine, int nCmdShow)
{
 // Register the window class
 const wchar_t CLASS_NAME[] = L"WindowClass";
 WNDCLASS wc = { };
 wc.lpfnWndProc = WindowProc;
 wc.lpszClassName = CLASS_NAME;
 wc.hInstance = hInstance;
 RegisterClass(&wc);
 // Create the window
 HWND hwnd = CreateWindowEx(
  0,
  CLASS_NAME,
  L"MyFirstWindow",
  WS_OVERLAPPEDWINDOW,
  CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,CW_USEDEFAULT,
  NULL,NULL,hInstance,NULL);

 if(hwnd == 0)
  return 0;
 // Show the window
 ShowWindow(hwnd,nCmdShow);
 nCmdShow = 1;
 // The Message loop
 MSG msg = { };
 while(GetMessage(&msg,NULL,0,0))
 {
  TranslateMessage(&msg);
  DispatchMessage(&msg);
 }
 return 0;
}
// Window Procedure function
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
 switch(uMsg)
 {
 case WM_DESTROY:PostQuitMessage(0); return 0;
 case WM_PAINT:
  {
   PAINTSTRUCT ps;
   HDC hdc = BeginPaint(hwnd,&ps);
   FillRect(hdc,&ps.rcPaint,(HBRUSH)(COLOR_WINDOW+5));
   EndPaint(hwnd,&ps);
  }return 0;
 case WM_CLOSE:
  {
   if(MessageBox(hwnd,L"Do you want to exit?",L"EXIT",MB_OKCANCEL)==IDOK)
    DestroyWindow(hwnd);
  }return 0;
 }
 return DefWindowProc(hwnd,uMsg,wParam,lParam); // Default Message Handling
}
