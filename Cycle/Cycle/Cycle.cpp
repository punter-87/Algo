// Cycle.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: */
struct Node {
int data;
struct Node* next;
};

void insert(Node** head, int data) {
	if (*head == nullptr){
		*head = new Node;
		(*head)->data = data;
		(*head)->next = nullptr;
		return;
	}

	Node *temp = new Node;
	temp->data = data;
	temp->next = *head;
	*head = temp;
	return;
}

void MoveNode(Node** a, Node** b){
	*a = *b;
	(*b) = (*b)->next;
	(*a)->next = nullptr;
}

Node* ShuffleMerge(Node*a, Node*b){
	if (a == nullptr){
		return b;
	}
	else if (b == nullptr)
	{
		return a;
	}

	Node*result = nullptr;
	Node**last = &result;
	while (a && b){
		MoveNode(last, &a);
		last = &((*last)->next);

		MoveNode(last, &b);
		last = &((*last)->next);
	}

	if (a)
	{
		*last = a;
	}
	if (b){
		*last = b;
	}

	return result;
}

void print(Node*head){
	while (head){
		cout << head->data << "\n";
		head = head->next;
	}
}

bool has_cycle(Node* head) {
	// Complete this function
	// Do not write the main method

	if (head == nullptr)
		return false;
	Node* slow = head;
	Node* fast = head;

	while (true){
		slow = slow->next;
		fast = fast->next;
		if (fast)
		{
			fast = fast->next;
		}
		else
		{
			return false;
		}
		if (slow == fast){
			return true;
		}
	}
	return true;
}



int _tmain(int argc, _TCHAR* argv[])
{
	int x;
	Node *head = nullptr;
	cin >> x;
	int flag = 0;
	while (x != -1)
	{
		insert(&head, x);
		cin >> x;
		flag++;
	}

	Node* head2 = nullptr;
	cout << "insert nodes for 2nd array \n";

	cin >> x;
	while (x != -1){
		insert(&head2, x);
		cin >> x;
	}

	Node* result = ShuffleMerge(head, head2);
	print(result);
	//Node *prev = nullptr;
	//Node *trav = head;

	//while (trav)
	//{
	//	prev = trav;
	//	trav = trav->next;
	//}

	//if (prev)
	//prev->next = head->next;
	//cout << has_cycle(head);
	//print(head);



	return 0;
}

