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

float distance(pair<int, int> One, pair<int, int> Two)
{
	return sqrt((Two.first - One.first) ^ 2 + (Two.second - One.second) ^ 2);
}

// define operations on pairs, it would be more elgant to write operator overloads for template pair but not for now

pair<int, int> sumpair(pair<int, int> One, pair<int, int> Two)
{
	pair<int, int> temp;
	temp.first = One.first + Two.first;
	temp.second = One.second + Two.second;
	return temp;
}

pair<int, int> subtrpair(pair<int, int> One, pair<int, int> Two)
{
	pair<int, int> temp;
	temp.first = One.first - Two.first;
	temp.second = One.second - Two.second;
	return temp;
}

//bool ispairin(pair<int, int> p, TextilePatch Rectangle) // checks if point is inside of a rectangle
//{
//	//pair<int, int> temp;
//	if (  )
//	return temp;
//}

int main()
{
	string TextileInitializator, InputFileName;
	set<TextilePatch> ListOfPatches;
	TextilePatch OneBigPatch, SinglePatch, marko;
	set <pair<int, int>> AvailableCutOutMap, PatchPairs;
	int AttemptedCutOut = 0;
	int Overlap = 0;
	int Increment = 0;

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

			// calculate and assign all points of the patch
			
			SinglePatch.LowerRight.first = SinglePatch.UpperLeft.first + SinglePatch.length;
			SinglePatch.LowerRight.second = SinglePatch.UpperLeft.second + SinglePatch.height;

			ListOfPatches.insert(SinglePatch);

			// check overlap
			//int sizebefore = PatchPairs.size();
			//int sizepatch = SinglePatch.WholeMap().size();
			//vector<string> Overlaps;
			//vector<string> AvailablePatches;
			////thisis so slow
			//PatchPairs.insert(begin(SinglePatch.WholeMap()),end(SinglePatch.WholeMap()));
			//int sizelater = PatchPairs.size();
			//Increment += sizelater - sizebefore;
			


			//if (sizelater != sizebefore + sizepatch)
			//{
			//	for (string str : SinglePatch.WholeMapString())
			//	{
			//		if (any_of(begin(Patches), end(Patches), 
			//			[str](string elem) { return str == elem; }))
			//		{
			//			Overlaps.push_back(str);
			//		}

			//	}
			//}
		//	Overlap += Size


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

	cout << "Max X is: " << MaxX << endl;
	cout << "Max Y is: " << MaxY << endl;

	cout << "min X is: " << minX << endl;
	cout << "min Y is: " << minY << endl;

	const int GlobalX = MaxX, GlobalY=MaxY;

	char GlobalMap[1000][1000];
	
	for (TextilePatch SinglePatch : ListOfPatches)
	{
		for (auto coord : SinglePatch.WholeMap() )
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

	for (int i = 0; i <= MaxX; i++ )
	{
		for (int j = 0; j <= MaxY; j++)
		{
			if ( GlobalMap[i][j] == 'd' )
			{
				Overlap++;
			}
		}

	}

	cout << "Overlapped square inches: " << Overlap << "!! " << endl;

		






    return 0;
}