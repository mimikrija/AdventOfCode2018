#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <iterator>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    

    // read input file
    string InputFileName;
    cout << "Input file name?";
    cin >> InputFileName;
    ifstream InputFile(InputFileName);

    // put input file into a vector
    vector<int> ListOfChanges{ istream_iterator<int>{InputFile},{} };

    // this is a vector for the second part
    vector<long> ListOfFrequencies;

    int Frequency = 0;
    for (int Change : ListOfChanges)
    {
    	Frequency += Change;
		ListOfFrequencies.push_back(Frequency);
		}

		cout << "Resulting frequency is: " << Frequency << "!! \n";
		// end of first part



		// second part: check which frequency appears twice
		// append new frequency to the list, check if it already exists

		bool Found = false;

		while ( !Found )
		{
		for (int Change : ListOfChanges)
		{
			Frequency += Change;
				
					//int p = count(ListOfFrequencies.begin(),ListOfFrequencies.end(), Frequency);
						Found = any_of(begin(ListOfFrequencies),end(ListOfFrequencies),
							[Frequency] (auto elem) {return elem == Frequency;}
								);
									//if (p > 0)
										if ( Found )
											{
												    
												    	    cout << "The first repeating frequency is: " << Frequency << "!! \n";
													    	    //Found = true;
														    	    break;
															    	}
																	
																		ListOfFrequencies.push_back(Frequency);
																			
																			}
																			}

																			    return 0;
																			    }
