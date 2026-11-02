# Validation scope

Initial local validation took place on Windows 11 x64 with Windhawk 1.7.3.

## Large icons

- x64 DLL compiled with `-Wall -Wextra -Werror`.
- Live folder changed from Details to large icons at 96 pixels.
- Disabling unloaded the mod and allowed Details view to remain.
- Re-enabling restored large icons.
- Subsequent function renaming preserved the executable logic.
- Removable drives were not physically connected for a test.

## Desktop Window Cards

- Both x86 and x64 DLLs compiled.
- Fourteen parsing/default checks passed.
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
