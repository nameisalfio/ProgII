/*
	Strutture dati 
	
	Array
	svantaggi: dimensione massima prefissata
	vantaggi: accesso ad ogni elemento in tempo costante O(1) grazie all'operatore di indicizzazione []
	
	Lista(Linked list)/Lista linkata semplice
	
	- Sequenza di elementi
	- Ogni elemento è collegato solo al suo successivo
	- Dimensione non nota a priori
	- Accessibile tramite un puntatore al primo elemento
	- Termina con un puntatore a Nil
	
	Nodo -> Valore
		 -> Puntatore all'elemento successivo
	
	L'accesso agli elementi avviene sfruttando un puntatore "Head", puntatore costante al primo elemento.
	L'ultimo elemento punta ad un nullptr "Nil".
	
	Head : Node*
	
	Node : Valore
		   Puntatore
		   
	Operazioni:
	1 Inserimento
	2 Accesso ad un elemento
	3 Ricerca
	4 Cancellazione
	5 Ordinamento
	6 Copia
	7 Controllo lista vuota
	
	Inserimentoin testa:
	- Creare del nuovo nodo
	- Il successivo del nuovo nodo deve essere head
	- Aggiornare Head facendola puntare al nuovo primo elemento
*/

#include<iostream>

using namespace std;

template<typename T>
class Node{

		T val;
		Node<T>* next;
		
		template<typename U>
		friend class List;
		
	public:
	
		Node(T val):val(val){
			next = nullptr;
		}
		
		//Operatore di redirezione dell'output <<
		//Operatore di redirezione dell'input >>
		//Friend : perchè l'operatore<< è della classe ostream ma deve accedere ai campi
		//			privati della classe nodo;

		friend ostream& operator<< (ostream& out, const Node<T>& node){
			out << "node val =" << node.val << " - next= " << node.next;
			return out;
		}
		
		Node<T>* getNext() const {
			return this -> next;
		}
};

template<typename T>
class List{
	
		Node<T>* head;
		
	public:
	
		List(){
			head = nullptr;
		}
		
		bool isEmpty(){
			return head == nullptr;
		}
		
		void insert(T val){
			if(this->isEmpty())
			{
				head = new Node<T>(val);
				return;
			}
		}
		
		void insertHead(T val){
			if(this->isEmpty())
			{
				this->insert(val);
				return;
			}
	
			Node<T>* tmp = new Node<T>(val);
			tmp->next = head;
			this->head = tmp;
		}

		void insertTail(T val){
			if(this->isEmpty())
			{
				this->insert(val);
				return;
			}
			
			Node<T>* ptr = head;
			while(ptr->next)  //prt->next != nullptr
			{
				ptr = ptr->getNext();
			}
			
			Node<T>* temp = new Node<T> (val);
			ptr -> next = temp;
		}

		Node<T>* getHead()const{
			return head;
		}

		friend ostream& operator<< (ostream& out, const List<T> &list){
			out << "\nList head=" << list.head <<endl;
			Node<T>* ptr = list.head;
			while(ptr) //ptr != nullptr
			{
				out << "\t" << *ptr << endl;
				ptr = ptr->getNext();
			}
			
			return out;
		}
};

int main(){
	
	List<int> lista;
	lista.insertHead(10);
	lista.insertHead(4);
	lista.insertHead(-19);
	
	cout << lista << endl;
	
	lista.insertTail(10);
	lista.insertTail(4);
	lista.insertTail(-19);
	
	cout << lista << endl;
}