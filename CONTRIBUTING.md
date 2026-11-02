# Adding and maintaining mods

1. Describe the idea, intended behavior, and scope in an issue.
2. Add a self-contained source file under `mods/` with a unique Windhawk ID.
3. Register it in `mods.json` and the root project table.
4. Write an English guide under `docs/<project>/README.md`, using the
   [project checklist](templates/NEW_MOD.md).
5. Use original project assets. Credit and license any third-party code or assets.
6. End the guide and the embedded Windhawk readme with credits, the repository
   link, and the maintainer's GitHub profile.
7. Compile supported architectures and test changed behavior in an isolated
   window or folder. Record limitations rather than claiming untested results.
8. Run `scripts/validate.ps1` and `scripts/build.ps1 -RunTests` before committing.

Keep existing IDs and setting keys stable when updating a mod. Change the
version for releases and document meaningful changes in the project's guide.
Avoid committing machine-specific registry exports, credentials, personal
file paths, application data, compiled executables, or local backups.

This repository builds mods; installing them remains an explicit local action.
Do not silently enable another mod or alter Windows security settings.
