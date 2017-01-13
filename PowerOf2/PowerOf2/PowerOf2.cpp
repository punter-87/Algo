// PowerOf2.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int power(string A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


	do
	{
		int x = 0, c = 0;
		string B;
		for (int i = 0; i < A.size(); i++)
		{
			if (A[i] < '0' || A[i] > '9')
				return 0;
			x = c * 10 + (A[i] - '0');

			if (i == A.size() - 1 && x % 2 != 0)
				return 0;

			if (x < 2 && i < A.size())
			{
				if (B.size() > 0) {
					B.insert(B.end(), '0');
				}
				x = x * 10 + (A[i + 1] - '0');
				i++;
				
			}

			c = x % 2;
			x = x / 2;

			B.insert(B.end(), (x + '0'));
		}

		A = B;
	} while (!(A.size() == 1 && A[0] - '0' == 1));
		return 1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	string x = "1";
	int y = power(x);
	cout << y;
	return 0;
}

