// BST.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

class BST{
private:
	struct node{
		int data;
	node* rc, *lc;
	node(int x)
	{
		data = x;
		rc = nullptr;
		lc = nullptr;
	}
	};

	node *root;

	void insertNode(node **root, int x) {
		if (!(*root))
		{
			*root = new node(x);
			return;
		}

		if ((*root)->data > x)
		{
			insertNode(&((*root)->lc), x);
		}
		else
		{
			insertNode(&((*root)->rc), x);
		}
	}

	void inorder(node*root)
	{
		if (!root)
			return;
		inorder(root->lc);
		cout << root->data << "  ";
		inorder(root->rc);
	}

	void InorderSuccPred(node *root, node*& pred, node*& succ, int x)
	{
		if (!root)
			return;

		if (root->data == x) {
			

			if (root->lc)
			{
				node * temp = root->lc;
				while (temp->rc) {
					temp = temp->rc;
				}

				pred = temp;
			}
			if (root->rc) {
				node *temp = root->rc;
				while (temp->lc) {
					temp = temp->lc;
				}

				succ = temp;
			}
		}

		else if (root->data > x) {
			succ = root;
			InorderSuccPred(root->lc, pred, succ, x);
		}
		else {
			pred = root;
			InorderSuccPred(root->rc, pred, succ, x);
		}
	}

public:
	BST() {
		root = nullptr;
	}

	void insert(int x) {
		insertNode(&root, x);
	}

	void inorder()
	{
		inorder(root);
	}
	void InPredSucc(int x)
	{
		node *pred = nullptr;
		node*succ = nullptr;
		InorderSuccPred(root, pred, succ, x);
		//cout << "Pred  " << pred ? pred->data : -1 <<endl;
		//cout << "Succ  " << succ ? succ->data : -1<< endl;
	}
};

int main()
{
	int x;
	BST bs;
	int n;

	cout << "Insert Number of node" << endl;
	cin >> n;
	while (n)
	{
		cin >> x;
		bs.insert(x);
		n--;
	}

	bs.inorder();
	cout << "calling succpred \n";
	cin >> x;
	bs.InPredSucc(x);
    return 0;
}

