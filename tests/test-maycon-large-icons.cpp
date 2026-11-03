// Decision-logic tests: no mod initialization, COM calls, or Explorer changes.
#include "../mods/maycon-large-folder-icons.wh.cpp"
#include <cassert>
#include <cstdio>

int main() {
    const std::wstring a = L"C:\\A", b = L"C:\\B";
    // Already in the desired view: nothing to do in either mode.
    assert(!ShouldApplyView(true, nullptr, a, FVM_ICON, 96, 96));
    // Wrong view or size: always-enforce reapplies.
    assert(ShouldApplyView(true, &a, a, FVM_DETAILS, 16, 96));
    assert(ShouldApplyView(true, &a, a, FVM_ICON, 48, 96));
    // Navigation-only: a manual change on the same path is respected...
    assert(!ShouldApplyView(false, &a, a, FVM_DETAILS, 16, 96));
    // ...but a new navigation or a newly seen tab is processed.
    assert(ShouldApplyView(false, &a, b, FVM_DETAILS, 16, 96));
    assert(ShouldApplyView(false, nullptr, a, FVM_DETAILS, 16, 96));
    // Two tabs in different folders are tracked independently (per-tab keys).
    std::map<ViewKey, std::wstring> previous{{1, a}, {2, b}};
    assert(!ShouldApplyView(false, &previous[1], a, FVM_DETAILS, 16, 96));
    assert(!ShouldApplyView(false, &previous[2], b, FVM_DETAILS, 16, 96));
    puts("PASS: 8 checks (view decision, navigation-only mode, per-tab tracking)");
}
