# D2RoomPrefs
A Proxy dll made for Diablo 2 Annihilus mod<br> 
It allows to set the Password and Game description to change of game server, As i was bored to type gs2 every time i'm farming !<br>
This is called only once Create Game interface is created (and also read your config file) so you can change of password/description manually in-game if wanted.<br>

## Installation
1. Extract the `Release.zip` directly in your game folder, eg: `C:\Program Files (x86)\Diablo II Annihilus\Apps\AnnihilusBeta`.
2. Make your changes in the `D2RoomPrefs.conf`.

## If the game crash
Go in your windows advanced system settings -> performance, and tick Activate DEP for all programs & services<br>
except those i select and add `Game.exe` from `C:\Program Files (x86)\Diablo II Annihilus\Apps\AnnihilusBeta` reboot and enjoy.<br>

Old Diablo 2 version that are still in x86, doesn't play well when the DEP is enabled on windows 10 or above.

## Building
1. Install vcpkg at https://vcpkg.io (skip if you already have it)
2. Go into the vcpkg directory and open up a terminal.
3. `vcpkg install minhook --triplet=x86-windows-static`
4. Open the .sln and build in release, you'll find the proxy dll `version.dll` with `D2RoomPrefs.conf` in the Release folder.<br>
`version_orig.dll` is taken from SysWOW64 folder.
