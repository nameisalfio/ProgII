
#include<iostream>
#include "graph_list.h"

using namespace std;

int main(){

	Graph_list<int> g;

	g.add_vertex(0);
	g.add_vertex(1);
	g.add_vertex(2);
	g.add_vertex(3);

	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(2,3);
	g.add_edge(0,3);

	cout << g << endl;
}