# Windhawk_Mods

A growing collection of Windows desktop customizations maintained by
[Dev_Maycon (MayconDIS)](https://github.com/MayconDIS).

Each mod has its own source, settings, guide, and attribution. New ideas can
be added to this repository without creating a separate repository per mod.

## Projects

| Project | Version | What it does | Guide |
| --- | --- | --- | --- |
| **Large icons — Dev_Maycon** | 1.1.1 | Keeps open Explorer folders in a consistent large-icon view. | [Read the guide](docs/large-icons/README.md) |
| **Desktop Window Cards — Dev_Maycon** | 1.0.2 | Turns minimized windows into animated, monitor-aware desktop cards. | [Read the guide](docs/desktop-window-cards/README.md) |

## Install a mod

1. Install [Windhawk](https://windhawk.net/) on Windows.
2. Open the desired `.wh.cpp` file in [`mods/`](mods/).
3. In Windhawk, select **Create a new Mod**, replace the template with that
   file's complete contents, and compile it using the editor.
4. Enable the mod and open **Details > Settings** to customize it.

Both mods have been submitted to the official Windhawk catalog and are
awaiting maintainer review. Track [Large icons (#6894)](https://github.com/ramensoftware/windhawk-mods/pull/6894)
and [Desktop Window Cards (#6895)](https://github.com/ramensoftware/windhawk-mods/pull/6895).
Submission does not mean catalog acceptance; use the manual installation
steps above while review is pending. Do not enable two editions of Desktop Window Cards at the
same time. Internal mod IDs retain their original spelling so existing
settings remain compatible.

## Build and validate

Requirements: Windows, PowerShell 7, and an installed Windhawk compiler.

```powershell
pwsh -File scripts/validate.ps1
pwsh -File scripts/build.ps1 -RunTests
```

Builds are written to `build/`. The build script compiles and tests sources;
it does not install DLLs, edit the registry, or restart applications.
The source versions were compiled with Windhawk 1.7.3 on Windows 11 x64.
See [validation notes](docs/VALIDATION.md) for tested and untested behaviors.

## Repository layout

```text
mods/       Self-contained Windhawk C++ mods
docs/       Per-project guides, provenance, and validation notes
assets/     Original project illustrations
scripts/    Build and repository validation tools
tests/      Parsing tests and isolated window/card probes
templates/  Checklist for adding another mod
```

## Add the next idea

Open an [idea issue](https://github.com/MayconDIS/Windhawk_Mods/issues/new?template=mod-idea.yml)
or follow [CONTRIBUTING.md](CONTRIBUTING.md). Every new project should have a
unique ID, a guide, tests appropriate to its behavior, and a credits section
linking back to this repository and the maintainer's profile.

## License and attribution

This collection is distributed under [GPL-3.0-only](LICENSE).
Large icons is a Dev_Maycon project developed with Codex assistance.
Desktop Window Cards is a derivative of HaVeN80's original mod; the original
engine's authorship is preserved in its source and guide. See
[THIRD_PARTY_NOTICES.md](THIRD_PARTY_NOTICES.md).

## Credits and links

- Maintainer and custom editions: **Dev_Maycon**.
- Development assistance: **OpenAI Codex**.
- Original Desktop Window Cards engine: **HaVeN80**.
- Repository: [MayconDIS/Windhawk_Mods](https://github.com/MayconDIS/Windhawk_Mods).
- GitHub profile: [MayconDIS](https://github.com/MayconDIS).
