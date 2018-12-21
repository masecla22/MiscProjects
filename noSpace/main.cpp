#include <windows.h>
#include <stdio.h>
#include <math.h>
#define ROUND(a) ((int) (a + 0.5))
/* set window handle */
static HWND sHwnd;
COLORREF color;
typedef struct {
    float x, y;
} Complex;
void SetWindowHandle(HWND hwnd){
    sHwnd=hwnd;
}
void setPixel(int x,int y,COLORREF color){
    if(sHwnd==NULL){
        MessageBox(NULL,"sHwnd was not initialized !","Error",MB_OK|MB_ICONERROR);
        exit(0);
    }
    HDC hdc=GetDC(sHwnd);
    SetPixel(hdc,x,y,color);
    ReleaseDC(sHwnd,hdc);
    return;
}
Complex complexSquare(Complex c){
    Complex cSq;
    cSq.x = c.x * c.x - c.y * c.y;
    cSq.y = 2 * c.x * c.y;
    return cSq;
}
int iterate (Complex zInit, int maxIter){
    Complex z = zInit;
    int cnt = 0;
    while((z.x * z.x + z.y * z.y <= 4)&& (cnt < maxIter)){
        z = complexSquare(z);
        z.x += zInit.x;
        z.y += zInit.y;
        cnt++;
    }
    return cnt;
}
void madelbrot(int nx, int ny, int maxIter, float realMin, float realMax, float imagMin, float imagMax){
    float realInc = (realMax - realMin) / nx;
    float imagInc = (imagMax - imagMin) / ny;
    Complex z;
    int x, y;
    int cnt;
    for(x = 0, z.x = realMin; x < nx; x++, z.x += realInc)
       for(y = 0, z.y = imagMin; y < ny; y++, z.y += imagInc ){
            cnt = iterate(z, maxIter);
            if(cnt == maxIter)
                color = RGB(255, 0, 0);
            else{
                color = RGB(0, cnt, 0);
            }
            setPixel(x, y, color);
       }
}
/* Window Procedure WndProc */
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam){
    switch(message){
        case WM_PAINT:
            SetWindowHandle(hwnd);
            madelbrot(750, 500, 500, -2.4,0.8,-1.4 ,1.4);
            break;
        case WM_CLOSE: // FAIL THROUGH to call DefWindowProc
            break;
        case WM_DESTROY:
            PostQuitMessage(0);
            return 0;
        default:
        break; // FAIL to call DefWindowProc //
    }
    return DefWindowProc(hwnd,message,wParam,lParam);
}
int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,LPSTR lpCmdLine,int iCmdShow){
    static TCHAR szAppName[] = TEXT("Fractals");
    WNDCLASS wndclass;
    wndclass.style         = CS_HREDRAW|CS_VREDRAW ;
    wndclass.lpfnWndProc   = WndProc ;
    wndclass.cbClsExtra    = 0 ;
    wndclass.cbWndExtra    = 0 ;
    wndclass.hInstance     = hInstance ;
    wndclass.hIcon         = LoadIcon (NULL, IDI_APPLICATION) ;
    wndclass.hCursor       = LoadCursor (NULL, IDC_ARROW) ;
    wndclass.hbrBackground = (HBRUSH) GetStockObject (WHITE_BRUSH) ;
    wndclass.lpszMenuName  = NULL ;
    wndclass.lpszClassName = szAppName ;
    // Register the window //
    if(!RegisterClass(&wndclass)){
        MessageBox(NULL,"Registering the class failled","Error",MB_OK|MB_ICONERROR);
        exit(0);
    }
    // Createw indow //
    HWND hwnd=CreateWindow(szAppName,"Mandelbrot Fractal - Programming Techniques",
                WS_OVERLAPPEDWINDOW,
                 CW_USEDEFAULT,
                 CW_USEDEFAULT,
                 CW_USEDEFAULT,
                 CW_USEDEFAULT,
                 NULL,
                 NULL,
                 hInstance,
                 NULL);
    if(!hwnd){
        MessageBox(NULL,"Window Creation Failed!","Error",MB_OK);
        exit(0);
    }
    // ShowWindow and UpdateWindow //
    ShowWindow(hwnd,iCmdShow);
    UpdateWindow(hwnd);
    // Message Loop //
    MSG msg;
    while(GetMessage(&msg,NULL,0,0)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    /* return no error to the operating system */
    return 0;
}
