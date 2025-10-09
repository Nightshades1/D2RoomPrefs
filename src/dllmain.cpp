#include "pch.h"
#pragma region ProxyDll
#pragma comment(linker, "/export:GetFileVersionInfoA=version_orig.GetFileVersionInfoA")
#pragma comment(linker, "/export:GetFileVersionInfoByHandle=version_orig.GetFileVersionInfoByHandle")
#pragma comment(linker, "/export:GetFileVersionInfoExA=version_orig.GetFileVersionInfoExA")
#pragma comment(linker, "/export:GetFileVersionInfoExW=version_orig.GetFileVersionInfoExW")
#pragma comment(linker, "/export:GetFileVersionInfoSizeA=version_orig.GetFileVersionInfoSizeA")
#pragma comment(linker, "/export:GetFileVersionInfoSizeExA=version_orig.GetFileVersionInfoSizeExA")
#pragma comment(linker, "/export:GetFileVersionInfoSizeExW=version_orig.GetFileVersionInfoSizeExW")
#pragma comment(linker, "/export:GetFileVersionInfoSizeW=version_orig.GetFileVersionInfoSizeW")
#pragma comment(linker, "/export:GetFileVersionInfoW=version_orig.GetFileVersionInfoW")
#pragma comment(linker, "/export:VerFindFileA=version_orig.VerFindFileA")
#pragma comment(linker, "/export:VerFindFileW=version_orig.VerFindFileW")
#pragma comment(linker, "/export:VerInstallFileA=version_orig.VerInstallFileA")
#pragma comment(linker, "/export:VerInstallFileW=version_orig.VerInstallFileW")
#pragma comment(linker, "/export:VerLanguageNameA=version_orig.VerLanguageNameA")
#pragma comment(linker, "/export:VerLanguageNameW=version_orig.VerLanguageNameW")
#pragma comment(linker, "/export:VerQueryValueA=version_orig.VerQueryValueA")
#pragma comment(linker, "/export:VerQueryValueW=version_orig.VerQueryValueW")
#pragma endregion
BOOL APIENTRY DllMain( HMODULE hModule,DWORD  ul_reason_for_call,LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        DisableThreadLibraryCalls(hModule);
        _beginthread((_beginthread_proc_type)LobbyPrefs::Initialize, NULL, NULL);
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

