/*
	Pile e Code sono strutture dati
	
	Pila(stack)
	Le operazioni di inserimento e rimozione di una pila avvengono sempre a partire
	dalla cima della pila stessa. Per questo motivo , le pile sono strutture dati di 
	tipo LIFO (last in first out).
	
	Proprietà(attributi):
	-Dimensione(numero di elementi)
	-Cima della pila(top)
	
	Metodi:
	-Push(aggiunge un elemento in cima)
	-Pop(rimuove un elemento in cima)
	-IsEmpty(verifica se la pila è vuota)
	
	Esistono liste limitate (con dimensione massima prefissata) e liste illimitate.
	DISCUSSIONE SULLA COMPLESSITA'
	push() -> O(1)
	pop() -> O(1)
	top() ->O(1)
*/

//Implementazione di uno stack dinamico

#include<iostream>
#include "Lez13.cpp"

using namespace std;

template<typename T>
class Stack : protected List<T>{
	
		int size = 0;
		
	public:
	
		Stack() : List<T>(){}
		
		bool isEmpty(){
			return size == 0;
		}
		
		Node<T>* get_top(){  //Restituisce la cima della pila
			
			if(isEmpty())  //Se non ci sono elementi
			{
				cerr << "Empty Stack" << endl;
				return nullptr;
			}
			
			return List<T>::getHead();  //Per l'implementazione data, la cima è sempre l'elemento in testa
		}
		
		void push(T val){  //Impilare un elemento
			
			List<T>::insertHead(val);
			size++;  //impilare un elemento comporta l'incremento della dimensione
		}
		
		Node<T>* pop(){  //Spilare un elemento
		
			if(isEmpty())
			{
				cerr << "\nPop function not avaible. Empty Stack! " << endl;
				return nullptr;
			}
			
			Node<T>* ptr = get_top();  //Mi salvo l'elemento in cima alla pila perchè dovrò ritornarlo
			List<T>::removeHead();  //Rimuovo l'elemento dalla cima
			size--;  //Decremento la dimensione
			return ptr;
			
		}
		
		friend ostream& operator<< (ostream& os, Stack<T> s){
			
			//os << (List<T>)s;  //Per richiamare il metodo della superclasse
			
			if(s.isEmpty())
			{
				os << "Empty Stack" << endl;
				return os;
			}

			os << "Size=" << s.size ;
			os << "\nTop-->\t" << *s.get_top() << endl;
			
			while(s.pop())
			{
				if(s.get_top())
				os << "\t" << *s.get_top() << "\n" ;
			}
			os << "End stack" << endl;
			
			return os;
		}
};

int main(){

	Stack<int> s;
	
	s.push(21);
	s.push(12);
	s.push(60);
	s.push(23);
	s.push(56);
	s.push(0);
	
	cout << s << endl;

}