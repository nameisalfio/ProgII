#ifndef GRAPH_VERTEX_H
#define GRAPH_VERTEX_H

#include<iostream>
using namespace std;

#include "Linked_list.h"

template <typename T>
class graph_vertex : public List<T>{

	public:

		graph_vertex(T key): List<T>(){ List<T>::insert(key); }

		graph_vertex() : graph_vertex(NULL){} 

		friend ostream& operator<< (ostream& os,const graph_vertex<T>&  v){

			//Il valore di head coincide con la chiave del vertice
			os << "\nGraph vertex with key " << v.head->getVal() << ": ";

			//Stampo la lista di nodi adiacenti al vertice
			os << "\tAdjecency list: ";
			Node<T>* ptr = v.head;
			
			if(!ptr->getNext())
				return os << "no adjacent vertex !" << endl;

			while(ptr->getNext())
			{
				ptr = ptr->getNext();
				os << "-->" << ptr->getVal();
			}
			os << endl;

			return os;
		}

};

#endif