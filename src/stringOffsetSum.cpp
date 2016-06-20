//============================================================================
// Name        : stringOffsetSum.cpp
// Author      : Enkeleid Hasko
// Version     :
// Copyright   : Your copyright notice
// Description : CUNY Tech Prep Assesment
//============================================================================

#include <iostream>
#include <string>
#include <vector>
#include "stringOffsetSum.h"

using namespace std;

int main()
{
	string str = "11Hello World";

	cout << str.size() << endl;

	OffsetSum s1(str);

	s1.displayOffsetSum();

	return 0;
}
