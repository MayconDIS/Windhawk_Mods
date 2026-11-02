// Disposable UI test window. It does not access personal data or files.
#include <windows.h>
LRESULT CALLBACK Procedure(HWND hwnd, UINT msg, WPARAM w, LPARAM l) {
    if(msg==WM_PAINT){PAINTSTRUCT ps; HDC dc=BeginPaint(hwnd,&ps); RECT r;GetClientRect(hwnd,&r);FillRect(dc,&r,(HBRUSH)(COLOR_WINDOW+1));SetBkMode(dc,TRANSPARENT);DrawTextW(dc,L"Maycon Desktop Cards\nMinimize this window to test the card.\nClick the card to restore this window.",-1,&r,DT_CENTER|DT_WORDBREAK);EndPaint(hwnd,&ps);return 0;}
    if(msg==WM_DESTROY){PostQuitMessage(0);return 0;}
    return DefWindowProcW(hwnd,msg,w,l);
}
int WINAPI wWinMain(HINSTANCE instance,HINSTANCE,PWSTR,int show) {
    WNDCLASSW cls{};cls.hInstance=instance;cls.lpfnWndProc=Procedure;cls.lpszClassName=L"MayconCardPreviewTest";cls.hCursor=LoadCursorW(nullptr,IDC_ARROW);RegisterClassW(&cls);
    HWND hwnd=CreateWindowW(cls.lpszClassName,L"Maycon Card Preview Test",WS_OVERLAPPEDWINDOW,CW_USEDEFAULT,CW_USEDEFAULT,800,500,nullptr,nullptr,instance,nullptr);
    if(!hwnd)return 1;ShowWindow(hwnd,show);MSG msg;while(GetMessageW(&msg,nullptr,0,0)>0){TranslateMessage(&msg);DispatchMessageW(&msg);}return 0;
}
