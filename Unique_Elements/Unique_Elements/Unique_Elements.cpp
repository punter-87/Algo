// Unique_Elements.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <map>

using namespace std;

void FindUniqueElements(vector<int>& vec)
{
	map<int, bool>mapElements;
	for each (int var in vec)
	{
		if (mapElements.find(var) == mapElements.end()){
			mapElements[var] = true;
		}
	}

	for each (pair<int, bool> var in mapElements)
	{
		cout << var.first << "  ";
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	vector<int> vec;
	int x;
	cin >> x;
	while (x != -1)
	{
		vec.push_back(x);
		cin >> x;
	}
	FindUniqueElements(vec);
	return 0;
}

