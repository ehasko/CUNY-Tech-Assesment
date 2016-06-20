#include <iostream>
#include <string>
#include <vector>

using namespace std;

class OffsetSum
{
	// member variables
private:
	// fetch and convert first two characters into a number
	string s;			// input string
	int range;			// range of subtring to analyze
	vector <char> v;	// unique characters in substring
public:
	// public member functions
	OffsetSum(string const &s);		// constructor
	void displayOffsetSum();
private:
	// private member functions
	void findUniqueChars();

};

OffsetSum::OffsetSum(string const &str)
{
	s = str;
	range = stoi(s.substr(0,3));
	if(range > s.size())
	{
		cout << "ERROR" << endl;
		exit(-1);
	}
	findUniqueChars();

}

void OffsetSum::findUniqueChars()
{
	for(int i = 2; i <= range+1; i++)
	{
		// cout << s[i] << endl;	// DEBUGGING

		// skip spaces
		if(s[i] == ' ')
			continue;

		// skip if character already in vector of charachters
		if(find(v.begin(), v.end(), s[i]) != v.end())
			continue;
		else
			v.push_back(s[i]);		// insert it
	}
}

void OffsetSum::displayOffsetSum()
{
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
