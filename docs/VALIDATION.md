# Validation scope

Initial local validation took place on Windows 11 x64 with Windhawk 1.7.3.

## Large Icons View for File Explorer

### 2.0.0 (hook-based)

- x64 DLL compiled with `-Wall -Wextra -Werror`.
- Eight decision-logic tests cover keep-enforcing and navigation-only modes.
- Live test on November 3, 2026 (Windows 11 x64, Windhawk 1.7.3), driving test
  folders through a COM probe and a simulated Ctrl+mouse wheel:
  - All three hooks resolved; the DLL loaded into `explorer.exe`.
  - New folders, navigation, and a folder saved in Details opened at 96 px.
  - Keep enforcing reverted Details, a 48 px icon size and Ctrl+wheel.
  - Navigation-only mode kept Details, 48 px and Ctrl+wheel changes until the
    next navigation, which applied 96 px again.
  - Settings changes re-applied to open folders; the desktop was not affected.
  - The first live run found that icon size changes bypass
    `SetCurrentViewMode`; the optional `_SwitchToViewModeAndIconSize` hook was
    added and verified.
- Not covered: real Explorer tabs (each navigation and window used its own
  view window), physical removable drives, and Open/Save dialogs.

### 1.x (polling, superseded)

- x64 DLL compiled with `-Wall -Wextra -Werror`.
- Live folder changed from Details to large icons at 96 pixels.
- Disabling unloaded the mod and allowed Details view to remain.
- Re-enabling restored large icons.
- Subsequent function renaming preserved the executable logic.
- Removable drives were not physically connected for a test.
- 1.1.1: the per-tab key was a COM proxy address and turned out not to be
  stable; replaced in 2.0.0.

## Desktop Window Cards

- Both x86 and x64 DLLs compiled.
- Sixteen parsing/default checks passed (1.0.2 adds exclusion list collection).
- The dedicated host loaded and stayed separate from Explorer.
- Minimizing an isolated test window produced one visible, uncloaked card
  measuring 560 x 376 pixels.
- Restoring the source window removed that card.
- Card-click restoration, drag-and-drop, multiple monitors, virtual desktop
  switching, and game performance were not separately tested.

## Repository build

The repository build reuses the included Windhawk compiler and places its
outputs under the ignored `build/` directory. It does not install the builds.
The metadata validator checks IDs, versions, guides, credits, and links.
These checks do not establish compatibility with every Windows build.

## Official catalog submissions

On November 2, 2026, both source files passed the official catalog's
`pr_validation.py` locally with their relative `mods/` paths and the
submitter's GitHub identity, with no warnings.

- [Large icons: PR #6894](https://github.com/ramensoftware/windhawk-mods/pull/6894).
- [Desktop Window Cards: PR #6895](https://github.com/ramensoftware/windhawk-mods/pull/6895).

Each request adds exactly one source file and discloses Codex assistance.
The cards submission also identifies HaVeN80's upstream engine and its
license. Maintainer review and catalog acceptance are still pending;
the pull request pages are the source of truth for their current status.
