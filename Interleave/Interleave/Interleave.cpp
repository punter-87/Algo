// Interleave.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

/**
* @input A : String termination by ' * @input B : String termination by ' * @input C : String termination by ' *
* @Output Integer
*/
bool isInterleave(string A, string B, string C) {

	int l = A.size();
	int m = B.size();
	int n = C.size();

	if (n != l + m)
		return 0;

	bool table[101][101][101];

	int i = 0;
	int j = 0;
	int k = 0;
	for (; i <= n; i++)
	{
		j = 0;
		for (; j <= l; j++)
		{
			k = 0;
			for (; k <= m; k++)
			{
				table[i][j][k] = false;

				if (i == 0 && j == 0 && k == 0)
					table[i][j][k] = true;


				if (i != j + k)
				{
					table[i][j][k] = false;
					continue;
				}

				if (j >= 1 && i >= 1 && C[i - 1] == A[j - 1])
					table[i][j][k] = table[i - 1][j - 1][k];

				if (k >= 1 && i >= 1 && C[i - 1] == B[k - 1])
					table[i][j][k] = table[i][j][k] | table[i - 1][j][k - 1];
			}
		}
	}

	return table[n][l][m];
}


int main()
{
	char *A = "b";
	char *B = "e";
	char *C = "be";
	bool res = isInterleave(A, B, C);
    return 0;
}

