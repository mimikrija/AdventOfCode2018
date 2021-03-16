#include<string>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <iostream>
#include <fstream>
#include <numeric>
#include <iterator>
#include <set>

using namespace std;

int main()
{
	// input text data to vector
	string InputFileName;
	cout << "Input file name?";
	cin >> InputFileName;
	ifstream InputFile(InputFileName);
	vector<string> RawInputData{ istream_iterator<string>{InputFile},{} };
	sort(begin(RawInputData), end(RawInputData)); //or use the prepare.sh script which sorts it in addition to removing spaces

	vector<pair<string, vector<int>>> Record, CleanRecord;

	auto it = begin(RawInputData);
	pair<string, vector<int>> onerecord;
	string guard;


	while (it != end(RawInputData))
	{

		string theswitch = (*it).substr(17, 1);

		// couldn't figure a way to make a case statement work

		if (theswitch == "G")
		{
			guard = (*it).substr(22, 5); // this doesn't take into account different number of digits of guard's name
		}

		if (theswitch == "f")
		{


			for (int minute = stoi((*(it)).substr(14, 2)); minute < stoi((*(it + 1)).substr(14, 2)); minute++)
			{
				onerecord.second.push_back(minute); // create list of minutes
			}
			onerecord.first = guard;
			Record.push_back(onerecord);
		}

		onerecord.second.clear();
		it++;

	}



	set<string> UniqueGuards;

	for (auto it : Record)
	{
		UniqueGuards.insert(it.first);
	}

	for (string guard : UniqueGuards)
	{
		pair<string, vector<int>> onerecord;
		auto it = begin(Record);
		while (it != end(Record))
		{
			onerecord.first = guard;
			if ((*it).first == guard)
			{
				onerecord.second.insert(onerecord.second.end(), (*it).second.begin(), (*it).second.end());
				it++;
			}

			else { it++; }
		}

		sort(onerecord.second.begin(), onerecord.second.end());
		CleanRecord.push_back(onerecord);


	}

	int solution11 = 0;
	int solution12;
	string TheSleepyGuard;
	vector<int> TheSleepyMinutes;

	for (auto onerecord : CleanRecord)
	{

		if (onerecord.second.size() >= solution11)
		{
			solution11 = onerecord.second.size();
			TheSleepyGuard = onerecord.first;
			TheSleepyMinutes = onerecord.second;
		}
	}
	int temp = 0;

	for (int minute = 0; minute < 60; minute++)
	{

		if (count(begin(TheSleepyMinutes), end(TheSleepyMinutes), minute) > temp)
		{
			solution12 = minute;
			temp = count(begin(TheSleepyMinutes), end(TheSleepyMinutes), minute);
		}
	}

	cout << "total minutes of the sleepiest guard times his sleepiest minute is " << TheSleepyGuard << " times " << solution12 << "!!" << endl;

	// second part: find the most frequent minute and relate it to the guard who it belongs to

	int mostfreqminutes = 0;
	string TheSleepyMinuteGuard;
	int tempo = 0;
	for (auto onerecord : CleanRecord)
	{
		for (int minute = 0; minute < 60; minute++)
		{

			if (count(begin(onerecord.second), end(onerecord.second), minute) > tempo)
			{
				mostfreqminutes = minute;
				tempo = count(begin(onerecord.second), end(onerecord.second), minute);
				TheSleepyMinuteGuard = onerecord.first;
			}
		}
	}

	cout << "most frequent minute is " << mostfreqminutes << " which belongs to guard " << TheSleepyMinuteGuard << "!!" << endl;

	return 0;
}