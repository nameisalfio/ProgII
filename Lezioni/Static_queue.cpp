//Implementezione statica --> c'è una dimensione massima raggiungibile dalla coda

#include<iostream>
using namespace std;

#define MAX_SIZE 1000

template<typename T>
class Static_queue{

		T*array;
		int size = 0; //Dimensione iniziale
		int maxSize ;

		//Indici di testa e coda
		int head = -1;
		int tail = -1;

	public:

		Static_queue(int maxSize = MAX_SIZE) : maxSize(maxSize){  //like a void constructor
			array = new T[maxSize];

		}

		//Static_queue() : maxSize(MAX_SIZE){}

		//Ragionare in termini di un array circolare 

		void enqueue(T val){  //Inserisce un elemento
			
			if(size == maxSize)
			{
				cerr << "\nFull queue" << endl;
				return;
			}

			if(head == -1)  //Problemi nella stampa 
				head = 0;
			
			tail = (++tail % maxSize); //Prima incremento l'indice della coda e lo faccio ricadere in uno dei possibili indici
			array[tail] = val; //Inserisco il nuovo elemento in coda agli altri
			size++; //Ciò provoca un aumento della dimensione
			return;
		}

		T dequeue(){  //Rimuove un elemento e lo restituisce

			if(size == 0)
			{
				cerr << "\nEmpty queue" << endl;
				return 0;
			}

			T tmp = array[head];  //Mi conservo il valore della testa per restituirlo in seguito
			head = (++head) % maxSize; //Prima incremento e poi faccio il modulo con la dimensione per lo stesso motivo di sopra
			size--; //Decremento la dimensione effettiva
			return tmp;
		}

		friend ostream& operator<< (ostream& os, Static_queue<T>& sq){

			if(sq.size == 0)
			{
				os << "\nEmpty queue" << endl;
				return os;
			}

			os << "\nSize= " << sq.size << endl;
			os << "\nMaxSize= " << sq.maxSize << endl;

			for(int i=sq.head, count=0; count < sq.size; count++)
			{
				os << "\tArray[" << i << "] = " << sq.array[i] << endl;
				i = (i+1) % sq.maxSize; //Incremento i e ne faccio il modulo per essere sicuro di verificare la condizione di uscita
			}
			
			os << endl;
			return os;
		}
};

int main(){

	Static_queue<int> sq(4);

	sq.enqueue(1);
	sq.enqueue(2);
	sq.enqueue(3);
	sq.enqueue(4);

	cout << sq ;

	sq.dequeue();
	sq.dequeue();

	cout << sq ;

	sq.enqueue(5);
	sq.enqueue(6);

	cout << sq ;
}

	


