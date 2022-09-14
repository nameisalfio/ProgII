#ifndef VERTEX_H
#define VERTEX_H

#include<iostream>
using namespace std;

template <typename T>
class vertex{

	protected:

		T key;

		template<typename U>
		friend class Graph; //friendship

	public:

		vertex(T key) : key(key){}

		vertex() : vertex(NULL){} //void constructor

		bool operator== (vertex<T>& v){return this->key == v.key;}

		T get_key()const{return this->key;}

		friend ostream& operator<< (ostream& os, const vertex<T>& v){return os << v.key ;}

};

#endif