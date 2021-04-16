#include <iostream>
#include <Windows.h>
#include "ok.h"
#include <fstream>  
#include <string>

using namespace std;

LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);

void Dl()
{
    int x = GetSystemMetrics(SM_CXSCREEN);
    int y = GetSystemMetrics(SM_CYSCREEN);
    HWND upW = GetForegroundWindow();
    HDC upH = GetDC(upW);
    HDC desktop = GetDC(NULL);

    upW = GetForegroundWindow();
    upH = GetDC(upW);
    desktop = GetDC(NULL);



    BitBlyat(desktop, 0, 0, x, y, GetDC(NULL), 0, 0, 0x999999);




    while (true)
    {
        upW = GetForegroundWindow();
        upH = GetDC(upW);
        desktop = GetDC(NULL);

        BitBlyat(desktop, 0, 0, x, y, GetDC(NULL), 0, 0, 0x777777);


        BitBlyat(desktop, -69, 69, x, y, GetDC(NULL), 12, 12, 0x999999);

        BitBlt(desktop, 10, 10, x, y, GetDC(NULL), 2, 2, 0x999999);
        BitBlt(desktop, -10, -10, x, y, GetDC(NULL), -2, -2, 0x888888);
        BitBlt(desktop, 0, 0, x, y, GetDC(NULL), 6, 6, 0x999999);
        BitBlt(desktop, 143, 61, x, y, GetDC(NULL), 10, 10, 0x333333);

        Sleep(0);



    }


}

int main(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR atgs, int ncmdshow)
{
    Dl();

    /*WNDCLASSW w = { 0 };
    w.hbrBackground = (HBRUSH)COLOR_WINDOW;
    w.hCursor = LoadCursor(NULL,IDC_HAND);
    w.hInstance = hInst;
    w.lpszClassName = L"MainWnd";
    w.lpfnWndProc = WindowProcedure;


    if (!RegisterClassW(&w)) 
        return -1;
    

    CreateWindowW(L"MainWnd",L"hi",WS_OVERLAPPEDWINDOW | WS_VISIBLE, 666, 420, 500, 500,
        NULL, NULL, NULL, NULL);

    

    MSG msg = { 0 };

   
    while (GetMessage(&msg, NULL, NULL, NULL))
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

   */

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp)
{
    switch (msg)
    {
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProcW(hWnd, msg, wp, lp);
    }
}

