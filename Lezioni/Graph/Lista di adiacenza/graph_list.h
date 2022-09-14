#ifndef GRAPH_LIST_H
#define GRAPH_LIST_H

#include "graph_vertex.h"

template<typename T>
class Graph_list{

		//Lista di graph_vertex<T> in cui ogni nodo sarà il primo elemento di una lista
		List<graph_vertex<T>> vertices; 

		int n_vertex = 0;
		bool isOriented;

	public:

		Graph_list(bool isOriented = true) : isOriented(isOriented){}

		void add_vertex(T key){

			graph_vertex<T> toInsert(key);  //Lista di un solo vertice
			vertices.insertTail(toInsert);
			n_vertex ++;
		}

		void add_edge(T key1, T key2){

			//Istanzio due nodi a cui assegno i vertici cercati(se esistono)
			Node<graph_vertex<T>>* node1 = search(key1);
			Node<graph_vertex<T>>* node2 = search(key2);

			if(node1 && node2)
			{
				//devo aggiungere node2 alla lista di adiacenza di node 1 per creare l'arco
				//getVal() mi restituisce la lista contenuta nel nodo
				node1->getVal().insertTail(key2);
				if(!isOriented)
					node2->getVal().insertTail(key1);
			}
			else
			{
				if(!node1)
					cerr << "There isn't vertex with key " << key1 << endl;
				else
					cerr << "There isn't vertex with key " << key2 << endl;
			}
		}

		Node<graph_vertex<T>>* search(T key){

			if(n_vertex == 0)
			{
				cerr << "Graph is Empty!" << endl;
				return nullptr;
			}

			Node<graph_vertex<T>>* ptr = vertices.getHead();
			while(ptr)
			{
			//ptr è un Node*
			//ptr->getVal() è la sua parte informativa, ovvero una "List<graph_vertex<T>>"(lista di vertici adiacenti)
			//ptr->getVal().getHead() è il vertice in testa alla lista di vertici adiacenti (un graph_vertex<T>*)
			//key == ptr->getVal().getHead()->getVal() è la parte informativa del vertice (un tipo T)

				if(key == ptr->getVal().getHead()->getVal())
					return ptr;

				ptr = ptr->getNext(); //scorro tutti i vertici del grafo
			}

			return nullptr;
		}

		friend ostream& operator<< (ostream& os, const Graph_list<T>& g){

			if(g.n_vertex == 0)
				return os << "\nEmpty Graph" << endl;

			if(!g.isOriented)
				os << "\nGraph isn't oriented";
			else 
				os << "\nGraph is oriented";

			os << "\tNumber of vertices: " << g.n_vertex << endl;
			return os << g.vertices << endl;

		}

};

#endif