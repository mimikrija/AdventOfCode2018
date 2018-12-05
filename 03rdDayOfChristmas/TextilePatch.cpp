#include "TextilePatch.h"

using namespace std;
auto TextilePatch::DelimiterPosition(string InputString, string delimiter)
{
	return InputString.find(delimiter) + 1;
}

//TextilePatch::TextilePatch(std::string ID, std::map<int, int> Coordinates, int length, int width):ID(ID), Coordinates(Coordinates), height(height), width(width)
//{
//}

TextilePatch::TextilePatch(std::string RawInput)
{

	height = stoi(RawInput.substr(DelimiterPosition(RawInput,"x")));
	RawInput.erase(DelimiterPosition(RawInput, "x"));

	length = stoi(RawInput.substr(DelimiterPosition(RawInput, ": ")));
	RawInput.erase(DelimiterPosition(RawInput, ": "));

	//Coordinates.second = stoi(RawInput.substr(DelimiterPosition(RawInput, ",")));
	//RawInput.erase(DelimiterPosition(RawInput, ","));

	//Coordinates.first = stoi(RawInput.substr(DelimiterPosition(RawInput, " @ ")));
	//RawInput.erase(DelimiterPosition(RawInput, " @ "));

	//ID = RawInput;
}
