
#include <string>
#include <iostream>
#include <iterator>
#include <fstream>
#include <algorithm>
#include <string>
#include <stdio.h>
#include <ctype.h>

using namespace std;

bool upperlower(char first, char second)
{
	return ( abs(int(first) - int(second)) == 32 );
}


int main()
{
	string Sequence, InputFileName, OriginalSequence;


	cout << "Input File name? " << endl;
	cin >> InputFileName;
	ifstream InputFile;

	InputFile.open(InputFileName);
	Sequence = { istream_iterator<char>{InputFile},{} };
 



int it=0;

while ( it < Sequence.length() )
{

	    if ( upperlower(Sequence[it],Sequence[it+1]) )
		{
		    Sequence.erase(it,2);
		    if ( it>0 )
		    {
		        it--;
		    }
		   else
		   {
		       it=0;
		   }
		}
		else
		{
		    it++;
		}
		
	
}

	cout << " Resulting sequence length is: " << Sequence.length() <<"!!" << endl;
	
	


	return 0;

}