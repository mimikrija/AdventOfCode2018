#include "TextilePatch.h"
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include "math.h"


using namespace std;

auto DelimiterPosition(string InputString, string delimiter)
{
	return InputString.find(delimiter);
}


int main()
{
	string TextileInitializator, InputFileName;
	set<TextilePatch> ListOfPatches;
	TextilePatch SinglePatch;

	int Overlap = 0;
	

	set<string> Patches;
	
	cout << "Input File name? " << endl;
	cin >> InputFileName;
	ifstream InputFile;
	
	InputFile.open(InputFileName);
	set<string> ListOfRawInputs{ istream_iterator<string>{InputFile},{} };

	for ( string RawInput : ListOfRawInputs )
	{
			SinglePatch.height = stoi(RawInput.substr(DelimiterPosition(RawInput,"x")+1));
			RawInput.erase(DelimiterPosition(RawInput, "x"), string::npos);
		
			SinglePatch.length = stoi(RawInput.substr(DelimiterPosition(RawInput, ":")+1));
			RawInput.erase(DelimiterPosition(RawInput, ":"), string::npos);
		
			SinglePatch.UpperLeft.second = stoi(RawInput.substr(DelimiterPosition(RawInput, ",")+1));
			RawInput.erase(DelimiterPosition(RawInput, ","), string::npos);
		
			SinglePatch.UpperLeft.first = stoi(RawInput.substr(DelimiterPosition(RawInput, "@")+1));
			RawInput.erase(DelimiterPosition(RawInput, "@"), string::npos);
		
			SinglePatch.ID = RawInput;

			// calculate and assign all points/corners of the patch, assign area (for second part)
			
			SinglePatch.LowerRight.first = SinglePatch.UpperLeft.first + SinglePatch.length;
			SinglePatch.LowerRight.second = SinglePatch.UpperLeft.second + SinglePatch.height;

			SinglePatch.area = SinglePatch.length * SinglePatch.height;

			ListOfPatches.insert(SinglePatch);

	}

	int MaxX = 0;
	int MaxY = 0;
	int minX = 10'000;
	int minY = 10'000;

	for (TextilePatch SinglePatch : ListOfPatches)
	{
		if (SinglePatch.LowerRight.first > MaxX)
		{
			MaxX = SinglePatch.LowerRight.first;
		}
		if (SinglePatch.LowerRight.second > MaxY)
		{
			MaxY = SinglePatch.LowerRight.second;
		}
		if (SinglePatch.LowerRight.first < minX)
		{
			minX = SinglePatch.LowerRight.first;
		}
		if (SinglePatch.LowerRight.second < minY)
		{
			minY = SinglePatch.LowerRight.second;
		}
	}



	const int GlobalX = MaxX, GlobalY=MaxY;

	char GlobalMap[1000][1000]; // I don't know how to cast MaxX and MaxY as const to be used as dimensions for the global map
	string SolutionID;

	for (TextilePatch SinglePatch : ListOfPatches)
	{
		for (auto coord : SinglePatch.WholeMap())
		{

			if (GlobalMap[coord.first][coord.second] == 'f')
			{
				GlobalMap[coord.first][coord.second] = 'd';
			}
			else
			{
				if (GlobalMap[coord.first][coord.second] == 'd')
				{
				}
				else
				{
					GlobalMap[coord.first][coord.second] = 'f';
				}
			}
		}
	
	}

   // Overlap = count(begin(GlobalMap), end(GlobalMap), 'd'); // why does this not work

	for (int i = 0; i <= MaxX; i++)
	{
		for (int j = 0; j <= MaxY; j++)
		{
			if (GlobalMap[i][j] == 'd')
			{
				Overlap++;
			}
		}
	}

	

	
	for (TextilePatch SinglePatch : ListOfPatches)
	{
		int count = 0;
		for (int i = SinglePatch.UpperLeft.first; i <= SinglePatch.LowerRight.first; i++)
		{
			for (int j = SinglePatch.UpperLeft.second; j <= SinglePatch.LowerRight.second; j++)
			{
				if (GlobalMap[i][j] == 'f')
				{
					count++;
				}
			}
		}
	
		if (count == SinglePatch.area)
		{
			SolutionID = SinglePatch.ID;
		}
		
	}

	cout << "Overlapped square inches: " << Overlap << "!! " << endl;

	cout << "Single (?) unoccupied patch: " << SolutionID << "!! " << endl;


    return 0;
}