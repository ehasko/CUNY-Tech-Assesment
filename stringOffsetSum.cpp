//============================================================================
// Name        : stringOffsetSum.cpp
// Author      : Enkeleid Hasko
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void printStr(string const &s)
{
	// fetch and convert first two characters into a number
	string num = s.substr(0,3);
	int range = stoi(num);
	// cout << range << endl;	// DEBUGGING

	if(range < 1 || range > 20)
	{
		cout << "ERROR" << endl;
		exit(1);
	}

	// store substring into a vector
	vector <char> v;

	// insert unique characters into a vector
	for(int i = 2; i <= range+1; i++)
	{
		// cout << s[i] << endl;	// DEBUGGING

		// skip if character already in vector of charachters
		if(find(v.begin(), v.end(), s[i]) != v.end())
			continue;
		else
			v.push_back(s[i]);		// insert it
	}

	char c;
	int sum = 0;
	int firstInd = 0;	// index of first character occurrence

	// runs N number of times, where N is the # of unique characters
	for(int i = 0; i < v.size(); i++)
	{
		c = v[i];
		cout << c;	// DEBUGGING

		// finds index of first occurrence by scanning substring
		for(int i = 2; i <= range+1; i++)
		{
			if(s[i] == c)
			{
				firstInd = i;
				// cout << "i = " << (i - 1) << endl;		// DEBUGGING
				int k = 1; // offset index

				for(int j = firstInd + 1; j <= range+1; j++)
				{
					// DEBUGGING
					// cout << "k = " << k << endl;
					// cout << "sum = " << sum << endl;

					if(s[j] == c)
						sum += k;
					k++;
				}

				cout << ' ' << sum << endl;
				break;	// we reached the end of the string
			}

			sum = 0;

		}

	}

}


int main() {
	// string str = "06ababab";
	string str = "12hello world!";

	printStr(str);

	return 0;
}
