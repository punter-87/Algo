// Anagrams.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;

int number_needed(string a, string b) {
	int ar1[26] = { 0 };
	int ar2[26] = { 0 };
	for (int i = 0; i < b.length(); i++)
	{
		ar2[b.at(i) - 97]++;
	}
	for (int i = 0; i < a.length(); i++)
	{
		ar1[a.at(i) - 97]++;
	}

	int count = 0;
	for (int i = 0; i < 26; i++){
		count += abs(ar1[i] - ar2[i]);
	}

	return count;
}

int main(){
	string a;
	cin >> a;
	string b;
	cin >> b;
	cout << number_needed(a, b) << endl;
	return 0;
}
