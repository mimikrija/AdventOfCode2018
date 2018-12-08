
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

int ResultLength (string Sequence)
{
    int it=0;

while ( it < Sequence.length() )
{

	    if ( upperlower(Sequence[it],Sequence[it+1]) )
		{
		    Sequence.erase(it,2);
		    //cout << "Sequence length is now: " << Sequence.length() << endl;
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
return Sequence.length();
}



int main()
{
	string Sequence, InputFileName;


	cout << "Input File name? " << endl;
	cin >> InputFileName;
	ifstream InputFile;

	InputFile.open(InputFileName);
	Sequence = { istream_iterator<char>{InputFile},{} };



// first part

	cout << " Resulting sequence length is: " << ResultLength(Sequence) <<"!!" << endl;
	
// second part
	int OptimalSize = Sequence.length();
	
	for ( int c=65; c <= 90; c++)
	{
	    string ShorterSequence = Sequence;
	    int newsize = Sequence.length() - count_if( begin(Sequence),end(Sequence), [c](char elem) { return ( int(elem)==c || int(elem)==c+32 );});
	    remove_if( begin(ShorterSequence),end(ShorterSequence), [c](char elem) { return ( int(elem)==c || int(elem)==c+32 );});
	    ShorterSequence.resize(newsize);
	    
	    int temp = ResultLength(ShorterSequence);
	    
	    //cout << " Resulting sequence length is, if we remove letter " << char(c) << " is: " << temp <<"!!" << endl;
	    
	    if ( temp < OptimalSize )
	    {
	        OptimalSize = temp;
	    }
	   
	    
	    
	}
	
	cout << "Optimal sequence length is " << OptimalSize << "!!" << endl;

	return 0;

}