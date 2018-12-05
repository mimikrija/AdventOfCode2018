#include "TextilePatch.h"
#include <string>

using namespace std;
//auto TextilePatch::DelimiterPosition(string InputString, string delimiter)
//{
//	return InputString.find(delimiter);
//}

TextilePatch::TextilePatch():ID("id"), Coordinates({}), length(0), height(0)
{
}

//TextilePatch TextilePatch::Fill(string RawInput) //ID(" "), Coordinates({ 0,0 }), length(0), height(0)
//{
//
//	height = stoi(RawInput.substr(DelimiterPosition(RawInput,"x")+1));
//	RawInput.erase(DelimiterPosition(RawInput, "x"), string::npos);
//
//	length = stoi(RawInput.substr(DelimiterPosition(RawInput, ":")+1));
//	RawInput.erase(DelimiterPosition(RawInput, ":"), string::npos);
//
//	Coordinates.second = stoi(RawInput.substr(DelimiterPosition(RawInput, ",")+1));
//	RawInput.erase(DelimiterPosition(RawInput, ","), string::npos);
//
//	Coordinates.first = stoi(RawInput.substr(DelimiterPosition(RawInput, "@")+1));
//	RawInput.erase(DelimiterPosition(RawInput, "@"), string::npos);
//
//	ID = RawInput;
//}

//bool operator<(const std::pair<int, int> &left, const  std::pair<int, int>  &right)
//{
//	return left.first < right.first;
//}

bool operator<(const TextilePatch &left, const TextilePatch  &right)
{
	return left.ID < right.ID;
}

//TextilePatch operator+=(const TextilePatch & left, const TextilePatch & right)
//{
//	return (left.WholeMap).insert(right.WholeMap);
//}

std::set<std::pair<int, int>> TextilePatch::WholeMap()
{
	std::set<std::pair<int, int>> tempset;
	for (int l = Coordinates.first; l < Coordinates.first+length; l++)
	{
		for (int h = Coordinates.second; h < Coordinates.second+height; h++)
		{
			tempset.insert(make_pair(l, h));
		}
	}
	return tempset;
}

std::set<std::string> TextilePatch::WholeMapString()
{
	std::set<std::string> tempset;
	for (int l = Coordinates.first; l < Coordinates.first + length; l++)
	{
		for (int h = Coordinates.second; h < Coordinates.second + height; h++)
		{
			tempset.insert(std::to_string(h) + "x"+ std::to_string(l));
		}
	}
	return tempset;
}

int TextilePatch::MapSize()
{
	int temp = WholeMap().size();
	return temp;
}