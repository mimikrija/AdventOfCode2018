#include "TextilePatch.h"
#include <string>

using namespace std;


TextilePatch::TextilePatch():ID("id"), UpperLeft({}), length(0), height(0)
{
}

//TextilePatch TextilePatch::Fill(string RawInput) //ID(" "), UpperLeft({ 0,0 }), length(0), height(0)
//{
//
//	height = stoi(RawInput.substr(DelimiterPosition(RawInput,"x")+1));
//	RawInput.erase(DelimiterPosition(RawInput, "x"), string::npos);
//
//	length = stoi(RawInput.substr(DelimiterPosition(RawInput, ":")+1));
//	RawInput.erase(DelimiterPosition(RawInput, ":"), string::npos);
//
//	UpperLeft.second = stoi(RawInput.substr(DelimiterPosition(RawInput, ",")+1));
//	RawInput.erase(DelimiterPosition(RawInput, ","), string::npos);
//
//	UpperLeft.first = stoi(RawInput.substr(DelimiterPosition(RawInput, "@")+1));
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



std::set<std::pair<int, int>> TextilePatch::WholeMap()
{
	std::set<std::pair<int, int>> tempset;
	for (int l = UpperLeft.first; l < UpperLeft.first+length; l++)
	{
		for (int h = UpperLeft.second; h < UpperLeft.second+height; h++)
		{
			tempset.insert(make_pair(l, h));
		}
	}
	return tempset;
}






