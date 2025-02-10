#pragma once
static class LobbyPrefs
{
public:
	struct Config
	{
		std::wstring Desc;
		std::wstring Password;
	};
	enum KeyType
	{
		DESC,
		PASSWORD
	};
	static void Initialize();
	static void ParseConfig();
};