# Large Icons View for File Explorer — changelog

## 2.0.0

- Renamed to **Large Icons View for File Explorer** with the new mod ID
  `explorer-large-icons-view`. Settings of the previous ID
  (`maycon-large-folder-icons`) are not carried over.
- Event-driven: hooks `CDefView::UIActivate` and `CDefView::SetCurrentViewMode`
  in `shell32.dll` instead of polling every Explorer window, plus an optional
  hook on `CDefView::_SwitchToViewModeAndIconSize` so icon size changes
  (Medium icons, Ctrl+mouse wheel) are also enforced. Folders open
  directly in large icons; the *Check interval* setting was removed.
- Fixed: navigation-only mode tracks each view window (one per tab and
  navigation), so manual view changes are kept, also after a minimized window
  is restored.
- Documented that Explorer saves the forced view per folder, and how to restore
  default views with **Reset Folders**.

## 1.1.1

- Navigation-only mode keyed by tab (superseded in 2.0.0: the key was a COM
  proxy address and was not stable).

## 1.1.0

- Dev_Maycon branding and English documentation.
