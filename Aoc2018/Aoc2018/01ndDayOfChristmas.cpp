/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
C#, VB, Perl, Swift, Prolog, Javascript, Pascal, HTML, CSS, JS
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;


int main()
{
    


string InputFileName;
cout << "Input file name?";
cin >> InputFileName;
ifstream InputFile(InputFileName);
bool Found = false;

vector<int> ListOfChanges{ istream_iterator<int>{InputFile},{} };

vector<long> ListOfFrequencies;

int Frequency = accumulate(begin(ListOfChanges), end (ListOfChanges),0);
cout << "Resulting frequency is: " << Frequency << "!! \n";

//this is for the second part
Frequency = 0;
for (int Change : ListOfChanges)
{
	Frequency += Change;
	ListOfFrequencies.push_back(Frequency);
}



vector<long> ListOfUniqueFrequencies = ListOfFrequencies;


sort(ListOfFrequencies.begin(),ListOfFrequencies.end());

while ( !Found )
{
for (int Change : ListOfChanges)
{
	Frequency += Change;
	auto p = find(ListOfFrequencies.begin(),ListOfFrequencies.end(), Frequency);
	if (*p != 0) //what if the frequency is zero???
	{
	    
	    cout << "The first repeating frequency is: " << *p << "!! \n";
	    Found = true;
	    break;
	}
	ListOfFrequencies.push_back(Frequency);
}
}

    return 0;
}
