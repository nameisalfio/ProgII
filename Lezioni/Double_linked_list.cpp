#include<iostream>
#include<sstream>
using namespace std;

template<typename T>
class DLNode{
	
		T val;  //parte informativa
		DLNode<T>* next;  //puntatore al nodo successivo
		DLNode<T>* prev;  //puntatore al nodo precedente
		
		static int count ;
		
		template<typename C>
		friend class DLList;  //per dare accesso ai contenuti privati della classe DLNode
	
	public:
	
		DLNode(T val) : val(val) {
			
			//Ogni nodo, dopo l'istanziazione, è considerato "isolato", quindi i collegamenti sono nulli
		
			this->next = nullptr;
			this->prev = nullptr;
			
			count ++;
		}
		
		T getVal()const{ return this->val; }
		
		DLNode<T>* getNext()const{ return this->next; }
		
		DLNode<T>* getPrev()const{ return this->prev; }
		
		friend ostream& operator<< (ostream& out, const DLNode<T>& node){
				out << node.val ;
				//out << 	"prev= " << node.prev << " - node val =" << node.val << " - next= " << node.next;
				return out;
		}
};

template<typename T>
int DLNode<T> :: count = 0;

template<typename T>
class DLList{
	
	protected:

		DLNode<T>* head;  //Puntatore al primo elemento della lista
		DLNode<T>* tail;  //Puntatore all'ultimo elemento della lista
		
	public:
		
		DLList(){

			//Inizialmente la lista è considerata "vuota". In una Empty-list non vi sono collegamenti. 

			head = nullptr;
			tail = nullptr;
		}
		
		bool isEmpty(){

			//Devo valutare che anche tail sia nullptr

			return (head == nullptr &&  tail == nullptr); 
		}
		
		DLNode<T>* getHead()const{
			return this->head;
		}
		
		DLNode<T>* getTail()const{
			return this->tail;
		}
		
		unsigned int getLen()const{
			return DLNode<T> :: count;
		}
		
		void insert(T val){

			if(this->isEmpty())
			{
				head = new DLNode<T>(val);
				tail = head;  //La coda coincide con la testa
				return;
			}
		}

		void insertHead(T val){
			
			if(this->isEmpty())
			{
				insert(val);
				return;
			}
			
			DLNode<T>* toinsert = new DLNode<T>(val);  //Elemento da inserire
			toinsert->next = head;  //Il successivo del nuovo nodo è la testa
			head->prev = toinsert;  //Il precedente della testa diventa il nuovo nodo
			head = toinsert;  //Il nodo inserito diventa la nuova testa
		}
		
		void insertTail(T val){
			
			if(this->isEmpty())
			{
				insert(val);
				return;
			}
			
			DLNode<T>* toinsert = new DLNode<T>(val);
			toinsert->prev = tail;  //Il precedente del nuovo nodo diventa la vecchia coda
			tail ->next = toinsert; //Il successivo della vecchia coda diventa il nuovo nodo
			tail = toinsert;  //Il nuovo nodo diventa la nuova coda
		}
		
		void insertInOrder(T val){
			
			if(isEmpty())
			{
				insert(val);
				return;
			}			
			
			if(val <= head->val)  //Se l'elemento è minore del primo
			{
				insertHead(val);
				return;
			}
			
			if(val >= tail->val)  //Se l'elemento è maggiore dell'ultimo
			{
				insertTail(val);
				return;
			}
		
			DLNode<T>* tmp = head; 
			
			//Si assume che la lista sia già ordinata
			
			while(tmp->next && val >= tmp->val)
			{
				if(val <= tmp->next->val)
					break;
				
				tmp = tmp->next;
			}
			
			DLNode<T>* toinsert = new DLNode<T>(val);
			toinsert->prev = tmp;
			toinsert->next = tmp->next;
			
			tmp->next->prev = toinsert;
			tmp->next = toinsert;
		}
		
		void removeHead(){
			
			if(this->isEmpty())
			{
				cerr << "Empty list !" << endl;
				return;
			}
			
			DLNode<T> :: count --;
			
			if(head == tail) //Se c'è un solo elemento 
			{
				DLNode<T>* ptr = head;
				head = nullptr;  //Annullo i collegamenti
				tail = nullptr;
				delete ptr;  //Elimino la testa
			}
			
			DLNode<T>* ptr = head;
			ptr->next->prev = nullptr;  //Annullo il collegamento alla testa
			head = ptr->next;  //La nuova testa diventa il successivo della vecchia testa
			
			delete ptr;  //Elimino la vecchia testa
		}
		
		void removeTail(){
			
			if(this->isEmpty())
			{
				cerr << "Empty list !" << endl;
				return;
			}
			
			DLNode<T> :: count --;
			
			if(head == tail) //Se c'è un solo elemento 
			{
				DLNode<T>* ptr = tail;
				head = nullptr;  //Annullo i collegamenti
				tail = nullptr;
				delete ptr;  //Elimino la coda
			}
			
			DLNode<T>* ptr = tail;
			ptr->prev->next = nullptr;  //annullo il collegamento alla coda
			tail = ptr->prev;  //La nuova coda diventa il precedente della vecchia coda
			
			delete ptr;  //Elimino la vecchia coda
		}

		void removeElement(T val){
			
			if(this->isEmpty())
			{
				cerr << "Empty list!" << endl;
				return;
			}
			
			//Se devo rimuovere il primo elemento 
			if(head->val == val){
				removeHead();
				return;
			}
			
			//Se devo rimuovere l'ultimo elemento
			if(tail->val == val){
				removeTail();
				return;
			}
			
			DLNode<T>* cur = head;
			DLNode<T>* prec = nullptr;
			
			while(cur->next && cur->val != val)
				cur = cur->next;  //Mi sposto in avanti
			
			
			if(cur->val != val)  //Se sono uscito perchè ho consumato la lista 
			{
				cerr << "Element with value " << val << " not found" << endl;
				return;
			}
			
			DLNode<T> :: count --;
			
			//Cur = elemento da eliminare adesso
			
			cur->prev->next = cur->next;  //Il precedente punta al successivo
			cur->next->prev = cur->prev;  //Il successivo punta al precedente
			
			delete cur;  //Perdo il riferimento all'elemento corrente
	
		}

		friend ostream& operator<< (ostream& os, const DLList<T> &l){
			os << "\nList head=" << l.head << endl ;
			os << "\nList tail=" << l.tail << endl << endl;
			DLNode<T>* ptr = l.head;
			while(ptr) //ptr != nullptr
			{
				os << "\t" << *ptr << endl;
				ptr = ptr->getNext();
			}
			
			return os;
		}
		
		string print_list(){
			
			if(isEmpty())
			{
				cerr << "Empty list!" << endl;
				return "";
			}
			
			stringstream ss;
			ss<<"List : \n"<<endl;
			DLNode<T>* tmp = this->head;
			
			while(tmp)
			{
				if(tmp == this->head)  //Just for correct tabulation
					ss<<"\t";
				
				ss<<tmp->getVal()<<" "; 
				tmp = tmp->getNext();
			}
			ss<<endl;
			
			ss << "\nLength : \n" << getLen() << endl;
			return ss.str();
		}
		
};
/*
int main(){
	
	DLList<int> list;
	
	list.insertHead(2);
	list.insertHead(1);
	list.insertHead(0);
	
	list.insertTail(3);
	list.insertTail(5);
	list.insertTail(7);
	
	cout << list << endl;

	cout << list.print_list() << endl;

	list.insertInOrder(4);
	list.insertInOrder(6);

	cout << list.print_list() << endl;
	
	cout << "Remove 0, 4 e 7" << endl;

	list.removeElement(0);
	list.removeElement(7);
	list.removeElement(4);
	
	cout << list.print_list() << endl;
}
*/