#include "TextilePatch.h"
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>


using namespace std;

auto DelimiterPosition(string InputString, string delimiter)
{
	return InputString.find(delimiter);
}

int main()
{
	string TextileInitializator, InputFileName;
	set<TextilePatch> ListOfPatches;
	TextilePatch OneBigPatch, SinglePatch, marko;
	set <pair<int, int>> AvailableCutOutMap;
	int AttemptedCutOut = 0;
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
		
			SinglePatch.Coordinates.second = stoi(RawInput.substr(DelimiterPosition(RawInput, ",")+1));
			RawInput.erase(DelimiterPosition(RawInput, ","), string::npos);
		
			SinglePatch.Coordinates.first = stoi(RawInput.substr(DelimiterPosition(RawInput, "@")+1));
			RawInput.erase(DelimiterPosition(RawInput, "@"), string::npos);
		
			SinglePatch.ID = RawInput;

			ListOfPatches.insert(SinglePatch);

			// check overlap
			int sizebefore = Patches.size();
			int sizepatch = SinglePatch.WholeMapString().size();
			vector<string> Overlaps;
			vector<string> AvailablePatches;
			Patches.insert(begin(SinglePatch.WholeMapString()),end(SinglePatch.WholeMapString()));
			int sizelater = Patches.size();
			if (sizelater != sizebefore + sizepatch)
			{
				for (string str : SinglePatch.WholeMapString())
				{
					if (any_of(begin(Patches), end(Patches), 
						[str](string elem) { return str == elem; }))
					{
						Overlaps.push_back(str);
					}

				}
			}
		//	Overlap += Size


	}


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