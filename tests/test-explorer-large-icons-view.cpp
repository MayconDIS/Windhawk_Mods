// Decision-logic tests: no mod initialization, hooks, COM calls, or Explorer changes.
#include "../mods/explorer-large-icons-view.wh.cpp"
#include <cassert>
#include <cstdio>

int main() {
    // Already in the desired view: nothing to do in either mode.
    assert(!ShouldApplyView(true, false, FVM_ICON, 96, 96));
    assert(!ShouldApplyView(false, false, FVM_ICON, 96, 96));
    // A newly shown view (not handled yet) is switched in both modes.
    assert(ShouldApplyView(true, false, FVM_DETAILS, 16, 96));
    assert(ShouldApplyView(false, false, FVM_DETAILS, 16, 96));
    // Keep enforcing: a manual change on a handled view is switched back,
    // including a different icon size in the same mode.
    assert(ShouldApplyView(true, true, FVM_DETAILS, 16, 96));
    assert(ShouldApplyView(true, true, FVM_ICON, 48, 96));
    // Navigation-only: a manual change on a handled view is kept.
    assert(!ShouldApplyView(false, true, FVM_DETAILS, 16, 96));
    assert(!ShouldApplyView(false, true, FVM_ICON, 48, 96));
    puts("PASS: 8 checks (view decision, keep-enforcing and navigation-only modes)");
}
