#include <set>
#include <map>
#include <algorithm>
#include "string.h"

TString::TString()
{
	length = 0;
	string = 0;
	countSplit = 0;
	countFinds = 0;
	countStringOfSymbols = 0;
}
TString::TString(char* _string) : TString()
{
	if (_string == 0) throw "Length of string == 0";
	length = Str_Len(_string) + 1;
	string = new char[length];
	for (int i = 0; i < length; i++)	string[i] = _string[i];
}
TString::TString(int len, char c) : TString()
{
	if (len <= 0) throw "Length of string == 0";
	length = len + 1;
	string = new char[length + 1];
	for (int i = 0; i < len; i++)  string[i] = c;
	string[len] = '\0';
}
TString::TString(const TString& p)
{
	countStringOfSymbols = p.countStringOfSymbols;
	countSplit = p.countSplit;
	countFinds = p.countFinds;
	length = p.length;
	string = new char[length];
	for (int i = 0; i < length; i++)	string[i] = p.string[i];
}
TString::~TString()
{
	if (string != 0)
	{
		delete[] string;
		string = 0;
	}
	length = 0;
	countSplit = 0;
	countFinds = 0;
	countStringOfSymbols = 0;
}

int TString::Str_Len(const char* str)
{
	int i = 0;
	while (str[i] != '\0')  i++;
	return i;
}

int TString::DoubleStr(int k)
{
	int count;
	std::string stringn;
	std::cout << "Enter count to repeat string: ";
	std::cin >> count;
	std::cout << "\n";

	for (int n = 0; n < count; n++) {
		stringn += string;
	}
	std::cout << "Your string is: " << stringn << "\n";
	stringn.clear();
	return 0;
}
int TString::Find(char c)
{
	for (int i = 0; i < length - 1; i++)	if (string[i] == c) return i;
	return -1;
}
int* TString::Find(TString& p)
{
	int* tmp = new int[length - 1];
	int count = 0;
	int k = 0;
	if (p.length > length)  throw "Word size is too big";
	for (int i = 0; i < length; i++)
	{
		bool flag = 1;
		for (int j = 0; j < p.length - 1; j++)
		{
			if (string[i + j] != p.string[j])
			{
				flag = 0;
				break;
			}
		}
		if (flag == 1) {
			tmp[k] = i;
			k++;
			count++;
		}
	}
	if (k == 0) throw "No entry";
	int* ind = new int[count];
	for (int i = 0; i < count; i++)	ind[i] = tmp[i];
	delete[] tmp;
	Set_Count_Of_Find_Indexes(count);
	return ind;
}
char TString::Most_Popular_Symbol()
{
	std::map<char, std::size_t> map;
	for (const auto& i : (std::string)string) {
		map[i]++;
	}
	std::cout << "The most frequent character in the string: ";
	std::cout << (*std::max_element(map.cbegin(), map.cend(), [](const auto& m1, const auto& m2) {
		return m1.second < m2.second;
		})).first << "\n";
	map.clear();
	return 0;
}
TString* TString::Split(char c)
{
	std::set <char> symbols;
	for (int n = 0; n < length; n++) {
		symbols.insert(string[n]);
	}
	std::cout << "Characters that are in the string:\n";
	for (auto& item : symbols) {
		int count = 0;
		for (int n = 0; n < length; n++) {
			if (string[n] == item) {
				count += 1;
			}
		}
		std::cout << item << ": " << count << "\n";
	}
	std::cout << "\n";
	symbols.clear();
	return 0;
}
int** TString::String_Of_Symbols() 
{
	std::set <char> symbols;
	for (int n = 0; n < length; n++) {
		symbols.insert(string[n]);
	}
	std::cout << "Characters that are in the string: ";
	for (auto& item : symbols) {
		std::cout << item << " ";
	}
	std::cout << "\n\n";
	symbols.clear();
	return 0;
}