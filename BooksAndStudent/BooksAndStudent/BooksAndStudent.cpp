// BooksAndStudent.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include<vector>
using namespace std;

int books(vector<int> &A, int B) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	if (A.size() < B)
		return -1;

	if (B == 0 && A.empty())
		return 0;

	int n = A.size();
	int sum = 0;
	int min = INT_MAX;
	int localMax = INT_MIN;
	for (int i = 0; i < n; i++){
		sum += A[i];
		vector<int> v(A.begin() + i + 1, A.end());
		int y = books(v, B - 1);
		
		if (y == -1)
			continue;

		localMax = sum > y ? sum : y;
		if (localMax < min){
			min = localMax;
		}
	}

	return min;
}


int _tmain(int argc, _TCHAR* argv[])
{
	vector<int>v = { 12, 34, 67, 90 };
	cout << books(v, 2);
	return 0;
}

