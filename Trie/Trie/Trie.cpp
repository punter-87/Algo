// Trie.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

typedef struct Node{
public:

	map<char, Node*>children;
	bool isEndOfWord;
	Node()
	{
		isEndOfWord = false;
	}
}Node;

class Trie{

	Node* root;

public:
	Trie()
	{
		root = new Node();
	}

	void Insert(string str)
	{
		Node* cur = root;
		int n = str.size();

		for (int i = 0; i < n; i++)
		{
			auto it= cur->children.find(str[i]);
			if (it == cur->children.end())
			{
				cur->children[str[i]] = new Node();
			}

			cur = cur->children[str[i]];
		}

		cur->isEndOfWord = true;
	}

	bool Search(string str)
	{
		Node *cur = root;
		int n = str.size();

		for (int i = 0; i < n; i++){
			auto it = cur->children.find(str[i]);

			if (it == cur->children.end())
				return false;

			cur = cur->children[str[i]];
		}

		return cur->isEndOfWord;
	}

	bool del(string str, int index, Node* cur)
	{
		if (index == str.size())
		{
			cur->isEndOfWord == false;

			return cur->children.size() == 0;
		}

		auto it = cur->children.find(str[index]);
		if (it == cur->children.end())
			return false;

		if (del(str, index + 1, it->second))
		{
			Node* temp = it->second->children[str[index]];
			delete(temp);

			return cur->children.size() == 0;
		}
	}

	bool del(string str)
	{
		delete(str, 0, root);
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	Trie T;

	T.Insert("abc");
	T.Insert("abcd");

	T.Insert("def");

	cout << "Find abc  " << T.Search("abc") << endl;
	cout << "Find ab  " << T.Search("ab") << endl;
	cout << "Find def  " << T.Search("def") << endl;
	return 0;
}

