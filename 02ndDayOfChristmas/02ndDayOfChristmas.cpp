#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string InputFileName;
	int HashCode = 1;
	bool TwoTimes = false;
	bool ThreeTimes = false;
	int CountTwos = 0;
	int CountThrees = 0;

	//vector<string> CorrectList;
	cout << "Input file name?";
	cin >> InputFileName;
	//cout << InputFileName << "\n";

	ifstream InputFile(InputFileName);
	std::vector<string> ListOfCodes{ istream_iterator<string>{InputFile},{} };;
	std::vector<string> CorrectList = ListOfCodes;
	//sort (ListOfCodes.begin(),ListOfCodes.end());
	//cout <<"List of Codes size is " << ListOfCodes.size() << ". \n";
	//string Code;
	for (auto Code : ListOfCodes)
	{
		//cout << "This is the original input string: " << Code << "\n";
		//auto last = unique(Code.begin(), Code.end());
		sort(Code.begin(), Code.end());
		//cout << Code << " sorted \n";
		string SearchKey = Code;
		string CopyCode = Code;
		auto last = unique(SearchKey.begin(), SearchKey.end());
		SearchKey.erase(last, SearchKey.end());
		//cout << " this is the sorted input string " << Code;
		//cout << ". this is the SearchKey " << SearchKey << ". \n";
		TwoTimes = false;
		ThreeTimes = false;
		for (auto counter : SearchKey)
		{
			int Appearance = count(Code.begin(), Code.end(), counter);
			if (Appearance == 2)
			{
				TwoTimes = true;
			}
			if (Appearance == 3)
			{
				ThreeTimes = true;
			}


		}
		if (TwoTimes)
		{
			CountTwos++;

		}
		if (ThreeTimes)
		{
			CountThrees++;
		}
	}





	cout << "HashCode is: " << CountTwos*CountThrees << "!!" << "\n";


	bool Found = false;
	vector<string> CheckList, NewList;
	int LengthOfWords = CorrectList[0].size();
	for (int CharCount = 0; CharCount < LengthOfWords; CharCount++)
	{
		NewList.clear();

		for (string Word : CorrectList)
		{
			NewList.push_back(Word.erase(CharCount, 1));
			//	cout << Word.erase(CharCount,1) << "\n";

		}
		sort(NewList.begin(), NewList.end());
		CheckList = NewList;
		auto last = unique(NewList.begin(), NewList.end());
		NewList.erase(last, NewList.end());

		if (NewList.size() != CheckList.size())
		{

			vector<string>::iterator it = adjacent_find(CheckList.begin(), CheckList.end());
			cout << "The first set of common (-1) characters is " << *it << "!!";
			Found = true;
			break;
		}
		if (Found)
		{
			break;
		}

	}

	return 0;
}