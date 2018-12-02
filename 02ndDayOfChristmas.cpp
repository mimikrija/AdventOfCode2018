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
    cout << "Input file name?";
    cin >> InputFileName;
    cout << InputFileName << "\n";
    ifstream InputFile(InputFileName);
    std::vector<string> ListOfCodes{istream_iterator<string>{InputFile},{}};;
    //sort (ListOfCodes.begin(),ListOfCodes.end());
    cout <<"List of Codes size is " << ListOfCodes.size() << ". \n";
    //string Code;
    for ( auto Code : ListOfCodes )
    {
        cout << "This is the original input string: " << Code << "\n";
        //auto last = unique(Code.begin(), Code.end());
        sort (Code.begin(), Code.end());
        //cout << Code << " sorted \n";
        string SearchKey = Code;
        auto last =  unique(SearchKey.begin(), SearchKey.end());
        SearchKey.erase(last, SearchKey.end());
        cout << " this is the sorted input string " << Code;
        cout << ". this is the SearchKey " << SearchKey << ". \n";
        TwoTimes = false;
        ThreeTimes = false;
        for (auto counter : SearchKey)
        {
            int Appearance = count(Code.begin(),Code.end(),counter);
            if ( Appearance == 2 )
            {
                TwoTimes = true;
            }
            if ( Appearance == 3 )
            {
                ThreeTimes = true;
            }
    
        
        }
        if ( TwoTimes ) 
        {
            CountTwos ++ ;
        }
        if ( ThreeTimes ) 
        {
            CountThrees ++ ;
        }
       // for ( auto c : last)
    //    {
      //      cout << c << " ";
    //    }
        //cout << "here is a unique one " << last;
        
        cout << "HashCode is: " << CountTwos*CountThrees << "!!";
    }
    
    

    return 0;
}

