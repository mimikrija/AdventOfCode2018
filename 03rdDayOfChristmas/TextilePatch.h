#pragma once
// this is the header file for the TextilePatch class defined in TextilePatch.cpp
#include <string>
#include <map>
#include <iterator>




class TextilePatch
{
private:
	
	auto DelimiterPosition(std::string InputString, std::string delimiter);

public:
	std::string ID;
	int length;
	int height;
	std::pair<int, int> Coordinates;
	TextilePatch(std::string RawInput);
	//TextilePatch(std::string ID, std::map<int, int> Coordinates, int length, int width); // constructor declaration
};