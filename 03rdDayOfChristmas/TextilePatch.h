#pragma once
// this is the header file for the TextilePatch class defined in TextilePatch.cpp
#include <string>
#include <set>
#include <iterator>




class TextilePatch
{
private:
	

public:
	std::string ID;
	int length;
	int height;
	std::pair<int, int> UpperLeft, LowerRight;

	// public class functions
	
	TextilePatch(); // constructor declaration
	
	std::set<std::pair<int, int>> TextilePatch::WholeMap();


friend bool operator< (const TextilePatch &left, const TextilePatch  &right);
//friend bool operator<(const std::pair<int,int> &left, const  std::pair<int, int>  &right);
//friend TextilePatch operator+= (const TextilePatch &left, const TextilePatch  &right);

};