#include <iostream>
#include <fstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include <cstring>

using namespace std;

int SecondsPerStep (string Letter)
{
    char temp = Letter[0];
    return int(temp) - 4;
}

int main()
{
	string InputFileName;
	vector<string> AllData, ListLeft, ListRight, Solution, Candidates;
	cout << "Input file name?";
	cin >> InputFileName;

	// read input line per line
	ifstream InputFile(InputFileName);
	std::string line;
	while (std::getline(InputFile, line))
	{
		AllData.push_back(line);
	}

	vector<pair <string, string>> LeftAndRight;

	// put letters in a vector of pairs
	for (auto it : AllData)
	{
		string Left = it.substr(5, 1);
		string Right = it.substr(it.find("step") + 5, 1);
		pair <string, string> Both(Left, Right);
		LeftAndRight.push_back(Both);
	}


	auto pend = LeftAndRight.end();
	auto cend = Candidates.end();

	while (LeftAndRight.size() != 0)
	{

		ListLeft = {};
		ListRight = {};
		for (auto both : LeftAndRight)
		{
			// construct left and right vectors
			ListLeft.push_back(both.first);
			ListRight.push_back(both.second);
		}

			// sort and remove duplicates
			sort(ListLeft.begin(), ListLeft.end());
			auto last = unique(ListLeft.begin(), ListLeft.end());
			ListLeft.erase(last, ListLeft.end());
			sort(ListRight.begin(), ListRight.end());
			last = unique(ListRight.begin(), ListRight.end());
			ListRight.erase(last, ListRight.end());

			// find difference between Left (needs to be ready) and Right (to be performed)
			set_difference(ListLeft.begin(), ListLeft.end(), ListRight.begin(), ListRight.end(), back_inserter(Candidates));
			sort(Candidates.begin(), Candidates.end());


			// the first candidate is always the first alphabetically
			string candidate = Candidates[0];
			pend = remove_if(LeftAndRight.begin(), LeftAndRight.end(), [candidate](pair <string, string> OnePair) {return (OnePair.first == candidate); });
			Solution.push_back(candidate);
			cend = remove_if(Candidates.begin(), Candidates.end(), [candidate](string OneCandidate) {return (OneCandidate == candidate); });
			Candidates.erase(cend,Candidates.end());
			LeftAndRight.erase(pend, LeftAndRight.end());

	}


	// add the last one:
	Solution.push_back(ListRight[0]);


	cout << "First part of the solution is: \n";
	for (auto it = Solution.begin(); it != Solution.end(); ++it)
	{
		std::cout << *it;
	}

// second part

int TotalSeconds,ElapsedTime = 0;
vector<int> Worker(5,0);

// put letters in a vector of pairs
	for (auto it : AllData)
	{
		string Left = it.substr(5, 1);
		string Right = it.substr(it.find("step") + 5, 1);
		pair <string, string> Both(Left, Right);
		LeftAndRight.push_back(Both);
	}


	pend = LeftAndRight.end();
	cend = Candidates.end();

	while (LeftAndRight.size() != 0)
	{

		ListLeft = {};
		ListRight = {};
		for (auto both : LeftAndRight)
		{
			// construct left and right vectors
			ListLeft.push_back(both.first);
			ListRight.push_back(both.second);
		}

			// sort and remove duplicates
			sort(ListLeft.begin(), ListLeft.end());
			auto last = unique(ListLeft.begin(), ListLeft.end());
			ListLeft.erase(last, ListLeft.end());
			sort(ListRight.begin(), ListRight.end());
			last = unique(ListRight.begin(), ListRight.end());
			ListRight.erase(last, ListRight.end());

			// find difference between Left (needs to be ready) and Right (to be performed)
			set_difference(ListLeft.begin(), ListLeft.end(), ListRight.begin(), ListRight.end(), back_inserter(Candidates));
			sort(Candidates.begin(), Candidates.end());


			// divide the work on 5 elves
			int i = 0;
			while ( i < 5 )
			{

			    if ( Worker[i] >= ElapsedTime )
			    {
			        i ++;
			        continue;
			    }
			    string candidate = Candidates[0];
			    pend = remove_if(LeftAndRight.begin(), LeftAndRight.end(), [candidate](pair <string, string> OnePair) {return (OnePair.first == candidate); });
			    Solution.push_back(candidate);
			    cend = remove_if(Candidates.begin(), Candidates.end(), [candidate](string OneCandidate) {return (OneCandidate == candidate); });
			    Candidates.erase(cend,Candidates.end());
			    LeftAndRight.erase(pend, LeftAndRight.end());
			    i++;
			    Worker[i] += SecondsPerStep(candidate);
			    if ( Candidates.size() < i ) break;

			}
			ElapsedTime += 60;

	}


	// add the last one:
	if (ListRight.size() > 0)
	{
	    TotalSeconds += SecondsPerStep(ListRight[0]);
	}





    //int TotalSeconds = SecondsPerStep(test);

	std::cout << "\n Second part of the solution is: " << TotalSeconds;


	return 0;
}