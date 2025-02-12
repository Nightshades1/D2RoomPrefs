#include "pch.h"

typedef int (*fp_sub_B480)(int a1, int a2);
fp_sub_B480 sub_B480_orig = nullptr;
DWORD D2Multi_Base = NULL;
LobbyPrefs::Config* D2RoomPrefs_Config = new LobbyPrefs::Config();
std::unordered_map<std::string, enum LobbyPrefs::KeyType> KeyValues
{
	{"desc",LobbyPrefs::KeyType::DESC},
	{"password",LobbyPrefs::KeyType::PASSWORD}
};

void LobbyPrefs::ParseConfig()
{
	std::ifstream pConfig("D2RoomPrefs.conf");
	std::string Line;
	while (std::getline(pConfig, Line))
	{
		if (Line.find_first_of(';'))
		{
			size_t delimiter_pos = Line.find('=');
			std::string Key = Line.substr(0,delimiter_pos);
			std::string Value = Line.substr(delimiter_pos + 1);
			switch ((LobbyPrefs::KeyType)KeyValues[Key])
			{
			case LobbyPrefs::DESC:
				if (Value.length() > 31)
				{
					Value.resize(31);
				}
				D2RoomPrefs_Config->Desc = std::wstring(Value.begin(),Value.end());
				break;
			case LobbyPrefs::PASSWORD:
				if (Value.length() > 15)
				{
					Value.resize(15);
				}
				D2RoomPrefs_Config->Password = std::wstring(Value.begin(),Value.end());
				break;
			}
		}
	}
}

static int Hook_Create_Game_Interface(int a1, int a2)
{
	auto x = sub_B480_orig(a1, a2);
	DWORD* UI_Menu_CreateRoom_Password_Obj = (DWORD*)(D2Multi_Base + 0x3A060);
	DWORD* UI_Menu_CreateRoom_Password_Count = (DWORD*)((char*)(*UI_Menu_CreateRoom_Password_Obj) + 0x50);
	DWORD* UI_Menu_CreateRoom_Password_Text = (DWORD*)((char*)(*UI_Menu_CreateRoom_Password_Obj) + 0x5C);
	DWORD* UI_Menu_CreateRoom_Desc_Obj = (DWORD*)(D2Multi_Base + 0x3A064);
	DWORD* UI_Menu_CreateRoom_Desc_Count = (DWORD*)((char*)(*UI_Menu_CreateRoom_Desc_Obj) + 0x50);
	DWORD* UI_Menu_CreateRoom_Desc_Text = (DWORD*)((char*)(*UI_Menu_CreateRoom_Desc_Obj) + 0x5C);
	LobbyPrefs::ParseConfig();
	*UI_Menu_CreateRoom_Desc_Count = D2RoomPrefs_Config->Desc.length();
	*UI_Menu_CreateRoom_Password_Count = D2RoomPrefs_Config->Password.length();
	wcscpy((wchar_t*)UI_Menu_CreateRoom_Password_Text, D2RoomPrefs_Config->Password.c_str());
	wcscpy((wchar_t*)UI_Menu_CreateRoom_Desc_Text, D2RoomPrefs_Config->Desc.c_str());
	return x;
}

void LobbyPrefs::Initialize()
{
#ifdef _DEBUG
	AllocConsole();
	FILE* pOut;
	SetConsoleTitle("DEBUG");
	freopen_s(&pOut, "CONOUT$", "w", stdout);
#endif
	do
	{
		D2Multi_Base = (DWORD)GetModuleHandle("D2Multi");
		Sleep(100);
	} while (!D2Multi_Base);
	MH_Initialize();
	MH_CreateHook((LPVOID)(D2Multi_Base + 0xB480), (LPVOID)Hook_Create_Game_Interface, (LPVOID*)&sub_B480_orig);
	MH_EnableHook(MH_ALL_HOOKS);
}