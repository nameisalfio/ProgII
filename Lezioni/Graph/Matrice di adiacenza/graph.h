#ifndef GRAPH_H
#define GRAPH_H

#include "vertex.h"

template<typename T>
class Graph{

		vertex<T>** vertices; //array di vortex pointer
		bool** adj;  //Matrice di adiacenza
		int max_size = 0; //Numero massimo di vertici 
		int n_vertex = 0; //Numero corrente di vertici
		bool isOriented;

	public:

		Graph(int max_size, bool isOriented = true): max_size(max_size), isOriented(isOriented){

			vertices = new vertex<T>*[max_size];

			adj = new bool*[max_size];
			for(int i=0; i<max_size; i++)
				adj[i] = new bool[max_size]{false}; //inizialmente la matrice è posta a false
		}

		void add_vertex(T key){

			if(n_vertex == max_size)
			{
				cerr << "Graph is full! " << endl;
				return;
			}

			vertices[n_vertex++] = new vertex<T>(key);


		}

		void add_edge(T key1, T key2){

			int i = search(key1);
			int j = search(key2);

			if(i != -1 && j != -1)
			{
				adj[i][j] = true;

				if(!isOriented)
					adj[j][i] = true;
			}
			else
			{
				if(i == -1)
					cerr << "There isn't vertex with key " << key1 << endl;
				else 
					cerr << "There isn't vertex with key " << key2 << endl;

			}
		}

		int search(T key){

			if(n_vertex == 0)
				return -1;

			for(int i=0; i<n_vertex; i++)
			{
				if(vertices[i]->key == key)
					return i;
			}

			return -1;
		}

		friend ostream& operator<< (ostream& os, Graph<T>& g){

			if(g.n_vertex == 0)
				return os << "\nEmpty Graph" << endl;

			os << "\nVertices: " << endl;
			for(int i=0; i<g.n_vertex; i++)
				os << "\nv[" << i << "] = " << g.vertices[i]->get_key() << "\t";

			os << endl;
			os << "\nEdges: \n" << endl;

			for(int i=0; i<g.n_vertex; i++){
				for(int j=0; j<g.n_vertex; j++)
				{
					if(g.adj[i][j])
						os << "(" << i << ")-----(" << j << ")" << endl;
				}
			}

			return os;
		}

		void print_adj(){

			cout << "\nAdj: \n" << endl;

			cout << "V:" ;
			for(int i=0; i<n_vertex; i++)
				cout << "\t" << *vertices[i] << "   ";
		
			cout << "\n------------------------------------\n";

			for(int i=0; i<n_vertex; i++)
			{
				for(int j=0; j<n_vertex; j++)
					cout << "\t" << adj[i][j] << "   ";

				cout << endl;
			}
		
		}
};

#endif