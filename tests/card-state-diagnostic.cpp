// Read-only integration probe for this edition's test window and card hosts.
#include <windows.h>
#include <dwmapi.h>
#include <cstdio>
#include <cwchar>
int cards=0, tests=0;
BOOL CALLBACK Observe(HWND hwnd,LPARAM){
    wchar_t cls[128]{};GetClassNameW(hwnd,cls,128);
    if(wcscmp(cls,L"MayconDesktopWindowCards_Card")==0){
        ++cards;RECT rect{};GetWindowRect(hwnd,&rect);DWORD cloaked=0;DwmGetWindowAttribute(hwnd,DWMWA_CLOAKED,&cloaked,sizeof(cloaked));
        printf("CARD visible=%d cloaked=%lu size=%ldx%ld\n",IsWindowVisible(hwnd),cloaked,rect.right-rect.left,rect.bottom-rect.top);
    }
    if(wcscmp(cls,L"MayconCardPreviewTest")==0){++tests;printf("TEST minimized=%d visible=%d\n",IsIconic(hwnd),IsWindowVisible(hwnd));}
    return TRUE;
}
int main(){EnumWindows(Observe,0);printf("TOTAL cards=%d testWindows=%d\n",cards,tests);}
