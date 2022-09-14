#ifndef BSTNODE_H
#define BSTNODE_H

#include<iostream>
using namespace std;

template<typename T>
class BSTNode{

	protected:

		T key;
		BSTNode<T>* left;
		BSTNode<T>* right;
		BSTNode<T>* parent;
		bool verbose ;

		template<typename U>
		friend class BST;

	public:

		BSTNode(T key, bool verbose = false) : key(key), verbose(verbose){
			left = nullptr;
			right = nullptr;
			parent = nullptr;
		}

		void setLeft(BSTNode<T>* left){ this->left = left; }
		void setRight(BSTNode<T>* right){ this->right = right; }
		void setParent(BSTNode<T>* parent){ this->parent = parent; }
		void set_key(T key){this->key = key;}

		BSTNode<T>* getLeft()const{ return this->left; }
		BSTNode<T>* getRight()const{ return this->right; }
		BSTNode<T>* getParent()const{ return this->parent; }
		T getKey()const{ return this->key; }

		friend ostream& operator<< (ostream& os, BSTNode<T>& b){

			if(b.verbose){

				os << "BSTNode: " << &b << endl;
				os << "Key =" << b.key << endl;
				os << "left->" << b.left << "\t right->" << b.right << "\t parent->" << b.parent << endl;
				return os;
			}

			return os << "Key = " << b.key << endl;
		}

/*
		~BSTNode(){

			delete left;
			delete rigth;
		}
*/
};	

#endif