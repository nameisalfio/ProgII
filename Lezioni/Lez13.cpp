/*
	Inserimento ordinato
	
	1-Scorrere la lista a partire dalla testa
	2-Verificare se l'elemento sia maggiore dell'elemento corrente e minore dell'elemento successivo
	3-Spostarsi fino a che l'elemento da inserire non si trova nella posizione corretta
	4-Il successivo del noto (next) deve essere l'elemento successivo 
	5-Stacco il collegamento del precedente facendolo puntare all'elemento aggiunto
	
	Definizione->Una lista vuota è ordinata
	
	Si assume che la lista di partenza sia già ordinata e che inserendo un elemento questa proprietà venga
	mantenuta
	
	Cancellazione lista
	
	1-Cancellare la testa = Spostare avanti il puntatore head
	2-Cancellare la coda = Il successivo del penultimo elento  diventa nullptr
	3-Cancellare un elemento = Verificare se l'elemento è corretto e poi il successivo del precedente 
								deve essere il successivo dell'elemento corrente
								
								
	Liste doppiamente linkate
	
	Hanno un puntatore all'elemento successivo e anche un puntatore al nodo precedente.
	
	DISCUSSIONE SULLA COMPLESSITA' COMPUTAZIONALI
	
	Liste semplici:
	-Insert/remove head-> O(1)
	-Insert/remove tail-> O(n) n=numero di elementi
	-Insert/Remove element(in mezzo alla lista)-> O(n/2) == O(n)
	->Con puntatore alla coda_Insert/remove tail->O(1)
	
*/

#include<iostream>
#include<sstream>

using namespace std;

template<typename T>
class Node{

		T val;
		Node<T>* next;
		static int count ;  //Variabile di classe
		
		template<typename U>
		friend class List;
		
	public:
	
		Node(T val):val(val){
			next = nullptr;
			count++;
		}
		
		//Operatore di redirezione dell'output <<
		//Operatore di redirezione dell'input >>
		//Friend : perchè l'operatore<< è della classe ostream ma deve accedere ai campi
		//			privati della classe nodo;

		friend ostream& operator<< (ostream& out, const Node<T>& node){
			//out << "node val =" << node.val << " - next= " << node.next;
			out <<  node.val ;
			return out;
		}
		
		T getVal()const{
			return this->val;
		}
		
		Node<T>* getNext() const {
			return this -> next;
		}
		
};

template<typename T>
int Node<T> :: count = 0;  //Una variabile di classe va inizializzata esternamente

template<typename T>
class List{
	
	protected:
		Node<T>* head;
		Node<T>* tail;
		
	public:
	
		List(){
			head = nullptr;
			tail = nullptr;
		}
		
		Node<T>* getHead()const{
			return head;
		}
		
		Node<T>* getTail()const{
			return tail;
		}
		
		unsigned int getLen()const{
			return Node<T> :: count;
		}
		
		bool isEmpty(){
			return head == nullptr;
		}
		
		void insert(T val){
			if(this->isEmpty())
			{
				head = new Node<T>(val);
				tail = head;
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
			
			/*
			Node<T>* ptr = head;
			while(ptr->next)  //prt->next != nullptr
			{
				ptr = ptr->getNext();
			}
			
			Node<T>* temp = new Node<T> (val);
			ptr -> next = temp;
			*/
			
			Node<T>* toinsert = new Node<T> (val);
			tail->next = toinsert;
			tail = toinsert;
		}

		void insertInOrderAscending(T val){
			
			if(this->isEmpty())
			{
				this->insert(val);
				return;
			}
			
			if(val <= head->val) //Controllo che il valore che voglio inserire sia minore o uguale del primo nodo
			{
				this->insertHead(val);
				return;
			}
			
			Node<T>* tmp = head;
			
			//Il while mi serve a posizionarmi sull'elemento corretto prima dell'inserimento
			
			while(tmp->getNext() && val >= tmp->val) //Finchè l'elemento da inserire è maggiore di quello corrente
			{
				if(val <= tmp->next->val) //Se l'elemento da inserire è minore del successivo
					break;
				
				tmp = tmp->next;
			}
			
			if(!tmp->next)  //Se non ci sono altri elementi dopo tmp
			{
				this->insertTail(val);
				return;
			}
			
			Node<T>* toInsert = new Node<T>(val);
			toInsert->next = tmp->next; //Collego il nodo da inserire al successivo di ptr
			tmp->next = toInsert; //Stacco il collegamento del precedente facendolo puntare all'elemento aggiunto
			return;
		}
		
		void insertInOrderDescending(T val){
			
			if(isEmpty())
			{
				cerr << "Empty list! " << endl;
				return;
			}
			
			if(val >= head->val)
			{
				insertHead(val);
				return;
			}
			
			Node<T>* tmp = head;
			
			while(tmp->next && val <= tmp->val) //Finchè l'elemento da inserire è minore di quello corrente
			{
				if(val >= tmp->val)
					break;
				
				tmp = tmp->next;
			}
			
			Node<T>* toinsert = new Node<T>(val);
			toinsert->next = tmp->next; //Collego il nodo da inserire al successivo di ptr
			tmp->next = toinsert; //Stacco il collegamento del precedente facendolo puntare all'elemento aggiunto
			return;
		
		}
		
		void insertInOrder(T val, string c){
			
			if(c == "Crescente")
			{
				insertInOrderAscending(val);
				return;
			}
			
			if(c == "Decrescente")
			{
				insertInOrderDescending(val);
				return;
			}
		}
		
		void removeHead(){
			
			if(this->isEmpty())
			{
				cerr << "Empty list!" << endl;
				return;
			}
			
			Node<T> :: count --;
			
			Node<T> * tmp = head;
			head = head -> next;  //Sposto in avanti la testa 
			delete tmp;  //Cancello l'indirizzo della vecchia testa
		}
		
		void removeTail(){
			
			if(this->isEmpty())
			{
				cerr << "Empty list!" << endl;
				return;
			}
			
			Node<T> :: count --;
			
			if(head == tail) //Se c'è un solo elemento 
			{
				Node<T>* ptr = tail;
				head = nullptr;  //Annullo i collegamenti
				tail = nullptr;
				delete ptr;  //Elimino la coda
			}
			
			Node<T>* cur = head;
			Node<T>* prev = nullptr;
			
			while(cur->next)
			{
				prev = cur;
				cur = cur->next;
			}
			
			tail = prev;
			prev->next = nullptr;
			delete cur;
			
		/*
			Node<T>* cur = head;  //Elemento corrente
			Node<T>* prev = nullptr; //Elemento precedente
			
			while(cur->next)  //Scorro fino al penultimo elemento
			{
				prev = cur;
				cur = cur->getNext();
			}
			
			prev->next = nullptr;  //Cancello l'elemento successivo al penultimo
			delete cur; //Cancello il vecchio indirizzo
		*/
		}

		void removeElement(T val){
			
			if(this->isEmpty())
			{
				cerr << "Empty list!" << endl;
				return;
			}
			
			if(head->val == val)
			{
				this->removeHead();
				return;
			}
			
			Node<T>* cur = head;  //Per scorrere la lista
			Node<T>* prev = nullptr;  //Precedente
			
			while(cur->next && cur->val != val)  //Mi posiziono al massimo al penultimo elemento
			{
				prev = cur;
				cur = cur->getNext();
			}
			
			if(!(cur->next)  && cur->val != val) //Se sono uscito dal while perchè ho finito gli elementi
				//if(cur->val != val)
			{
				cerr << "Element with value " << val << " not found" << endl;
				return;
			}
			
			Node<T> :: count --;
			
			prev->next = cur->next;  //il successivo del precedente deve essere il successivo dell'elemento corrente
			delete cur;  //Cancello
			return;
		}
	
		friend ostream& operator<< (ostream& out, const List<T> &list){
			out << "\nList head=" << list.head << endl;
			out << "\nList tail=" << list.tail << endl << endl;
			Node<T>* ptr = list.head;
			while(ptr) //ptr != nullptr
			{
				out << "\t" << *ptr << endl;
				ptr = ptr->getNext();
			}
			
			return out;
		}
		
		Node<T>* operator [] (T key){
			
			if(this->isEmpty())
				return nullptr;
			
			if(head == tail)
			{
				if(head->val == key)
					return head;
	
				//If the value of the single element is different from the search key
				return nullptr;
			}
			
			Node<T>* tmp = head;
			while(tmp)
			{
				if(tmp->val == key)
					return tmp;

				tmp = tmp->next;
			}

			//If the key isn't among the list's element
			return nullptr;
			
		}
		
		string print_list(){
			
			if(isEmpty())
			{
				cerr << "\nEmpty list!" << endl;
				return "";
			}
			
			stringstream ss;
			ss<<"\nList : \n"<<endl;
			Node<T>* tmp = this->head;
			
			while(tmp)
			{
				if(tmp == this->head)  //Just for correct tabulation
					ss<<"\t";
				
				ss<<tmp->getVal()<<" "; 
				tmp = tmp->getNext();
			}
			ss<<endl;
			ss << "\nLength : " << getLen() << endl ;
			return ss.str();
		}
};
/*
int main(){
	
	List<int> lista;
	
	lista.insertHead(3);
	lista.insertHead(5);
	lista.insertHead(9);
	lista.insertHead(0);
	
	cout << lista.print_list() << endl;
	
	lista.insertTail(8);
	lista.insertTail(4);
	
	cout << lista.print_list() << endl;
	
	lista.removeTail();
	
	cout << lista.print_list() << endl;
	
	cout << "Sostituisco l'elento 8 con 7" << endl;
	if(lista[8])
		*lista[8] = 7;
	else
		cerr << "Empty list or element not found!" << endl;
	
	cout << lista.print_list() << endl;
	
	//L'elemento 100 non è presente tra gli elementi della lista
	cout << "Sostituisco l'elento 100 con 7" << endl;
	if(lista[100])
		*lista[100] = 7;
	else
		cerr << "\nEmpty list or element not found!" << endl;
	
	
}*/