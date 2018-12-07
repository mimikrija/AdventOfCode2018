#pragma once
// this is the header file for the TextilePatch class defined in TextilePatch.cpp
#include <string>
#include <set>
#include <iterator>




class TextilePatch
{
private:
	
	//auto DelimiterPosition(std::string InputString, std::string delimiter);
	//std::set<std::pair<int,int>> WholeMap;
	int upperX, upperY, lowerX, lowerY;
	

public:
	std::string ID;
	int length;
	int height;
	std::pair<int, int> UpperLeft, LowerRight;

	TextilePatch();

	std::set<std::pair<int, int>> TextilePatch::WholeMap();
	//std::set<std::string> WholeMapString();
	int TextilePatch::MapSize();
	std::set<std::string> TextilePatch::WholeMapString();

	//TextilePatch Fill(std::string RawInput);
	//TextilePatch(std::string ID, std::map<int, int> Coordinates, int length, int width); // constructor declaration

friend bool operator< (const TextilePatch &left, const TextilePatch  &right);
//friend bool operator<(const std::pair<int,int> &left, const  std::pair<int, int>  &right);
//friend TextilePatch operator+= (const TextilePatch &left, const TextilePatch  &right);

bool TextilePatch::DoTheyOverlap(TextilePatch Piece1, TextilePatch Piece2);

std::pair<int, int> TextilePatch::CalculateOverlap(TextilePatch Piece1, TextilePatch Piece2);
};