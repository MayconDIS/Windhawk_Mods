# Large icons — DevMaycon

![Large icons — DevMaycon](https://raw.githubusercontent.com/MayconDIS/devmaycon-windhawk-mods/main/assets/large-icons.svg)

*Original project illustration.*

**A consistent folder view, wherever your files live.**

Created for DevMaycon with Codex assistance. This project keeps Explorer
folders in large-icon view using Windows Shell interfaces.

## Quick start

1. Enable this mod in Windhawk.
2. Open a regular folder in File Explorer.
3. Its view switches to large icons at the configured size.
4. Open **Details > Settings** to customize the behavior.

## What this project does

| Feature | Behavior |
| --- | --- |
| Consistent sizing | Uses 96 pixels by default; adjustable from 32 to 256. |
| Local and removable drives | Applies to open filesystem folders, including USB drives. |
| Network folders | Uses the same Shell view interface for network paths. |
| Keep enforcing | Reapplies the selected view after a manual change. |
| Navigation-only mode | Allows manual changes until the next folder navigation. |
| Lightweight updates | Checks open views; does not scan folder contents. |

## Settings

**Icon size:** 96 pixels corresponds to Large icons.
**Check interval:** 1500 milliseconds by default; lower values react sooner.
**Keep enforcing:** turn this off if you prefer to change a view temporarily.

## Scope and limitations

The desktop, Home, This PC, Recycle Bin, and Open/Save dialogs are excluded.
Minimized Explorer windows are processed after restoration. Tabs are processed
when the Shell exposes their views. A brief delay before applying the view is
normal. Removable drives were not physically connected during validation.

## Your files stay in place

This mod changes presentation only. It does not move, delete, upload, or index
your files and does not clear Explorer's saved view cache. It does not require
WinSetView. Disabling stops enforcement; Windows may retain the last view.

## Project files

- `maycon-large-folder-icons.wh.cpp` — complete source, settings, and this guide.
- `scripts/validate.ps1` — metadata, guide, and credit checks.
- `scripts/build.ps1` — reproducible build without installing the mod.
- `docs/large-icons/README.md` — this guide and recovery notes.

## Version 1.1.0

- DevMaycon branding and original English project documentation.
- Clearer function names for view processing and monitoring.
- Existing mod identity and user settings preserved during the update.


## Credits and links

Original project: **DevMaycon**, developed with Codex assistance. Licensed under **GPL-3.0-only**.

- Custom edition and maintenance: **DevMaycon**.
- Development assistance: **OpenAI Codex**.
- Repository: [MayconDIS/devmaycon-windhawk-mods](https://github.com/MayconDIS/devmaycon-windhawk-mods).
- GitHub profile: [MayconDIS](https://github.com/MayconDIS).
