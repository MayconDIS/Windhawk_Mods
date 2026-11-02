// Parse-only tests: no mod initialization, windows, hooks, or system changes.
#include "../mods/maycon-desktop-window-cards.wh.cpp"
#include <cassert>
#include <cstdio>

int main() {
    using namespace Configuration;
    assert(NormalizeExcludedApp(L"  \"C:/Program Files/My App/APP.EXE\" \t") ==
           L"c:\\program files\\my app\\app.exe");
    assert(NormalizeExcludedApp(L"  \r\n\t\"").empty());
    assert(NormalizeExcludedApp(L"VALORANT-Win64-Shipping.exe") ==
           L"valorant-win64-shipping.exe");
    assert(NormalizeExcludedApp(L"  cs2.exe  ") == L"cs2.exe");
    assert(ParseModifier(L"ctrl") == VK_CONTROL);
    assert(ParseModifier(L"alt") == VK_MENU);
    assert(ParseModifier(L"none") == 0);
    assert(ParseModifier(L"shift") == VK_SHIFT);
    assert(ParseModifier(L"unexpected") == VK_SHIFT);
    assert(ParseNativeAnimation(L"always") == Settings::NativeAnimation::Always);
    assert(ParseNativeAnimation(L"never") == Settings::NativeAnimation::Never);
    assert(ParseNativeAnimation(L"") == Settings::NativeAnimation::RestoreOnly);
    Settings defaults;
    assert(defaults.grid && !defaults.closeWindow && !defaults.includeExisting);
    assert(defaults.animationMs == 320);
    puts("PASS: 14 checks (exclusion normalization, modifier fallback, animation mode, defaults)");
}
