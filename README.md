# D2RoomPrefs
A Proxy dll made for Diablo 2 Annihilus mod<br> 
It allows to set the Password and Game description to change of game server, As i was bored to type gs2 every time i'm farming !<br>
This is called only once Create Game interface is created (and also read your config file) so you can change of password/description manually in-game if wanted.<br>

## Installation
1. Extract the `Release.zip` directly in your game folder, eg: `C:\Program Files (x86)\Diablo II Annihilus\Apps\AnnihilusBeta`.
2. Make your changes in the `D2RoomPrefs.conf`.

## Windows Permission
To be able to edit `D2RoomPrefs.conf` as a standard user instead of having to run any text editor as admin because you don't have the permission to modify the file

You can right click on `D2RoomPrefs.conf` -> `Properties` -> `Security` -> `Modify` -> Scroll down to your `Users (Your username\Your username)` and bellow tick `Modification` -> `Apply` -> `Ok`, Now you are free to edit it as a regular user.

## If the game crash
### Windows 10 and above
1. In your windows search bar, search for `exploit protection` and open it.
2. Click on the `Program Settings` category -> `Add Program to customize` and select `Choose exact file path`.
3. Add `Game.exe` from your installation folder, eg: `C:\Program Files (x86)\Diablo II Annihilus\Apps\AnnihilusBeta`.
4. Click on the new element that was added in the list then `Edit` -> Scroll down until you find `Data Execution Prevention (DEP)`<br>
Tick `Override system settings` and set the toggle to `off`, You only need to restart the game.

### Windows 8.1 and lower
* Go in your Windows `advanced system settings` -> `performance`, and tick `Activate DEP for all programs & services
except those i select` and add `Game.exe` from `C:\Program Files (x86)\Diablo II Annihilus\Apps\AnnihilusBeta` You need to restart your computer

Old Diablo 2 version that are still in x86, doesn't play well when the DEP is enabled.

## Building
1. Install vcpkg at https://vcpkg.io (skip if you already have it)
2. Go into the vcpkg directory and open up a terminal.
3. `vcpkg install minhook --triplet=x86-windows-static`
4. Open the .sln and build in release, you'll find the proxy dll `version.dll` with `D2RoomPrefs.conf` in the Release folder.<br>
`version_orig.dll` is taken from SysWOW64 folder.
