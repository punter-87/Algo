// WaterArea.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

// use B * H > (N - 1) * min(a1,an)
// B < N -1 ==> H > min(a1,an)
int maxArea(vector<int> &A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details


	int max = INT_MIN;
	int start = 0;
	int end = A.size() - 1;
	while (start < end)
	{
		int baseDiff = end - start;
		int temp;
		if (A[start] > A[end]){
			temp = A[end];
			end--;
		}
		else
		{
			temp = A[start];
			start++;
		}

		if (max < temp * baseDiff){
			max = temp * baseDiff;
		}
	}

	return max;
}



int _tmain(int argc, _TCHAR* argv[])
{
	vector<int>v = { 1, 5, 4, 3 };
	cout << maxArea(v);
	return 0;
}

