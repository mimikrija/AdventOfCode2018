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

			// calculate and assign bounds of the patch
			
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

	bool is;
	pair<int, int> Proba1(7, 6);
	pair<int, int> Proba2(1, 1);
	is = Proba1 == Proba2;
	is = Proba1 < Proba2;
	//is = Proba1 > Proba2;



	Proba1 = subtrpair(Proba1, Proba2);

	cout << PatchPairs.size()-Increment;

	for (TextilePatch SinglePatch : ListOfPatches)
	{
		for (pair<int, int> p : SinglePatch.WholeMap())
		{
			if ( any_of(begin(AvailableCutOutMap), end(AvailableCutOutMap), 
				[p](pair<int, int> elem) { return p.first == elem.first && p.second == elem.second; }))
			{
				Overlap++;
			}
			AvailableCutOutMap.insert(p);
		}
		AttemptedCutOut += SinglePatch.MapSize();
	}

	//cout << "Available cutout size is: " << AvailableCutOutMap.size() << ", " << endl;
	//cout << "The attempted size is: " << AttemptedCutOut << ", " << endl; // oh no, that's all of the overlaps
	 //cout << "Overlapped square inches: " << AttemptedCutOut - AvailableCutOutMap.size() << "!! " << endl; // oh no, that's all of the overlaps
	cout << "Overlapped square inches: " << Overlap << "!! " << endl; 

    return 0;
}