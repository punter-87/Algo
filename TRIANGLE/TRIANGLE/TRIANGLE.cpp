// TRIANGLE.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

int func(vector<vector<int> > &A) {
	int n = A.size();
	if (n == 0)
		return 0;
	vector<int>table = A[n - 1];

	for (int i = n - 2; i >= 0; i--)
	{
		int m = A[i].size();
		for (int j = 0; j < m; j++) {
			int small = table[j] < table[j + 1] ? table[j] : table[j + 1];
			table[j] = small + A[i][j];
		}
	}
	return table[0];
}

int main()
{
	vector<vector<int>> v;
	vector<int> temp;
	temp.push_back(2);
	v.push_back(temp);

	temp.clear();
	temp.push_back(6);
	temp.push_back(6);
	v.push_back(temp);

	temp.clear();

	temp.push_back(7);
	temp.push_back(8);
	temp.push_back(4);
	v.push_back(temp);

	cout << func(v)<<endl;
    return 0;
}

