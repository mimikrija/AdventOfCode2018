
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <set>
#include <vector>
#include <utility>
#include <algorithm>
#include "math.h"
#include <stdio.h>
#include <ctype.h>


using namespace std;

//auto DelimiterPosition(string InputString, string delimiter)
//{
//	return InputString.find(delimiter);
//}

bool upperlower(char first, char second)
{
	if ((isupper(first) && islower(second)) || (islower(first) && isupper(second)))
	{
		if ( first == toupper(second) || first == tolower(second))
		{
			return true;
		}
	}
}


int main()
{
	string Sequence, InputFileName;


	cout << "Input File name? " << endl;
	cin >> InputFileName;
	ifstream InputFile;

	InputFile.open(InputFileName);
	Sequence = { istream_iterator<char>{InputFile},{} };
	
	for (int c = 0; c < Sequence.length(); c++)
	{
		if ( upperlower(Sequence[c],Sequence[c+1]) )
		{
			cout  << "It cancels" << " because " << Sequence[c] << " and " << Sequence[c + 1] ;
		}
	}



	return 0;

}