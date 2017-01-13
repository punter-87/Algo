// Graph.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

enum color{
	white,
	gray,
	black
};

class Vertex{
public:
	int data;
	color c;
	Vertex* parent;
	vector<Vertex*> next;
	int d;
	int f;
	Vertex(int i){
		data = i;
		c = white;
		parent = nullptr;
		d = 0;
		f = 0;
	}
};



class Graph{

	vector<Vertex*> list;
	void DFS_Visit(Vertex* v);
	

public:
	void CreateGraphVertex(int n);
	void InsertEdges(int i, vector<int> adj);
	Vertex* GetAdjList(int index);
	void DFS();
	//void BFS(int s);
};


void Graph::CreateGraphVertex(int n){
	for (int i = 0; i < n; i++){
		Vertex*v = new Vertex(i);
		list.push_back(v);
	}
}

void Graph::InsertEdges(int i, vector<int> adj){
	if (list.size() < i){
		cout << "Vertex is out of Graph " << endl;
	}
	
	Vertex* v = list[i];
	for (int j = 0; j < adj.size(); j++){
		if (list.size() <= adj[j])
		{
			continue;
		}

		v->next.push_back(list[adj[j]]);
	}
}

void Graph::DFS_Visit(Vertex* u)
{
	static int time = 0;
	time++;
	u->d = time;
	u->c = gray;

	for each (Vertex* v in u->next)
	{
		if (v->c == white)
		{	
			v->parent = u;
			DFS_Visit(v);
		}
	}

	time++;
	u->c = black;
	u->f = time;
}

void Graph::DFS()
{
	for (int i = 0; i < list.size(); i++){
		if (list[i]->c == white){
			DFS_Visit(list[i]);
		}
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	int vertex;
	Graph g;
	cout << "Enter number of vertexes" << endl;
	cin >> vertex;
	g.CreateGraphVertex(vertex);

	for (int i = 0; i < vertex; i++){
		int edges;
		vector<int>adj;
		cout << "Enter the number of edges for vertex " << i + 1 << endl;
		cin >> edges;

		for (int j = 0; j < edges; j++){
			int edge;
			cin >> edge;
			adj.push_back(edge);
		}

		g.InsertEdges(i, adj);
	}

	g.DFS();
	return 0;
}

