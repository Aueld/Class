#pragma once

class Path
{
public:
	static bool ExistFile(string path);
	static bool ExistFile(wstring path);

	static bool ExistDirectory(string path);
	static bool ExistDirectory(wstring path);

	static string Combine(string path1, string path2);
	static wstring Combine(wstring path1, wstring path2);

	static string GetDirectoryName(string name);
	static wstring GetDirectoryName(wstring name);

	static string GetExtension(string path);
	static wstring GetExtension(wstring path);

};

