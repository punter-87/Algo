// QueueUsingTwoSTacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;

class MyQueue {

public:
	stack<int> stack_newest_on_top, stack_oldest_on_top;
	void push(int x) {
		if (stack_oldest_on_top.empty())
			stack_newest_on_top.push(x);

		else
			stack_oldest_on_top.push(x);

	}

	void pop() {

		
		if (!stack_newest_on_top.empty())
		{
			for (int i = 0; i < stack_newest_on_top.size() - 1; i++){
				stack_oldest_on_top.push(stack_newest_on_top.top());
				stack_newest_on_top.pop();
			}
			stack_newest_on_top.pop();

		}

		else if (!stack_oldest_on_top.empty())
		{
			for (int i = 0; i < stack_oldest_on_top.size() - 1; i++){
				stack_newest_on_top.push(stack_oldest_on_top.top());
				stack_oldest_on_top.pop();
			}

			stack_oldest_on_top.pop();
		}
	}

	int front() {
		if (!stack_newest_on_top.empty()){
			int temp;
			while (!stack_newest_on_top.empty()){
				temp = stack_newest_on_top.top();
				stack_newest_on_top.pop();
				stack_oldest_on_top.push(temp);
				
			}
			return temp;
		}
		else if (!stack_oldest_on_top.empty())
		{
			int temp;
			while (!stack_oldest_on_top.empty()){
				temp = stack_oldest_on_top.top();
				stack_oldest_on_top.pop();
				stack_newest_on_top.push(temp);
				
			}
			return temp;
		}
		return -1;
	}
};

int main() {
	MyQueue q1;
	int q, type, x;
	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> type;
		if (type == 1) {
			cin >> x;
			q1.push(x);
		}
		else if (type == 2) {
			q1.pop();
		}
		else cout << endl<<q1.front() << endl;
	}
	/* Enter your code here. Read input from STDIN. Print output to STDOUT */
	return 0;
}



int _tmain(int argc, _TCHAR* argv[])
{
	return 0;
}

