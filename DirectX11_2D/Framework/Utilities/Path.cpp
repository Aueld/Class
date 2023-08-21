#include "Framework.h"
#include "Path.h"

bool Path::ExistFile(string path)
{
	return false;
}

bool Path::ExistFile(wstring path)
{
	return false;
}

bool Path::ExistDirectory(string path)
{
	return false;
}

bool Path::ExistDirectory(wstring path)
{
	return false;
}

string Path::Combine(string path1, string path2)
{
	return string();
}

wstring Path::Combine(wstring path1, wstring path2)
{
	return wstring();
}

string Path::GetDirectoryName(string name)
{
	return string();
}

wstring Path::GetDirectoryName(wstring name)
{
	return wstring();
}

string Path::GetExtension(string path)
{
	return string();
}

wstring Path::GetExtension(wstring path)
{
	return wstring();
}
