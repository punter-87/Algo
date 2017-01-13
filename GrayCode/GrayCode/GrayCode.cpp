// GrayCode.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int covertStringToInt(string str){
	int num = 0;
	int n = str.size();
	for (int i =  n- 1; i >= 0; i--){
		int x = str[i] - '0';
		num += x * pow(2, n - i - 1);
	}

	return num;
}

vector<int> grayCode(int A) {
	// Do not write main() function.
	// Do not read input, instead use the arguments to the function.
	// Do not print the output, instead return values as specified
	// Still have a doubt. Checkout www.interviewbit.com/pages/sample_codes/ for more details

	int n = pow(2, A);
	vector<string>strs;
	string str1 = "0";
	string str2 = "1";

	strs.push_back(str1);
	strs.push_back(str2);

	for (int i = 0; strs.size() < n; i++){
		
		vector<string> temp;

		for (int j = 0; j < strs.size(); j++){
			temp.push_back("0" + strs[j]);
		}

		for (int j = strs.size() - 1; j >= 0; j--) {
			temp.push_back("1" + strs[j]);
		}
		strs = temp;
	}

	vector<int> v;
	for (int i = 0; i < strs.size(); i++){
		v.push_back(covertStringToInt(strs[i]));
	}

	return v;
}

int _tmain(int argc, _TCHAR* argv[])
{
	grayCode(3);
	return 0;
}

