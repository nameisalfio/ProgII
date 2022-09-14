/*
	OOP [object oriented programming]

	Principi base della OOP :
	
	1) Astrazione 
	2) Incapsulamento
	3) Ereditarietà
	4) Polimorfismo
	
	Astrazione :
	Generalizzare i concetti da affrontare per avere un interfaccia comune per tutti gli oggetti di quel tipo.
	
	Incapsulamento (information Hiding) :
	Utilizzo di "modificatori di accesso" in modo che alcune informazioni risultino publiche e che altre rimangano
	nascoste all'esterno e accessibili solo ai membri della classe stessa. 
	
	Ereditarietà :
	Meccanismo che consente livelli di astrazione gerarchici che consentono di conservare le proprietà della classe base 
	nelle classi derivate.
	
	Polimorfismo :
	Funzioni che hanno lo stesso nome ma assumono comportamenti diversi a seconda dell'oggetto chiamante.
	 il polimorfismo indicherà l'attitudine di un oggetto a mostrare più implementazioni per una singola
	funzionalità.
	Vantaggi del polimorfismo : 
	Facilità di manutenzione del codice.
	ex. per disegnare un triangolo basta creare un oggetto triangolo che eredita da figura_geometrica ed 
		ridefinire il corpo della funzione "disegna_figura"(overriding)
	
	Dati -> Variabili e funzioni di qualsiasi tipo. Se definiti all'interno di una classe vengono chiamate membri della 
			classe (attributi e metodi).
	
	Classe :
	Consente quindi di modificare i livelli di accesso ai membri della classe stessa. Il modificatore di accesso di 
	default è private.
	
	Struct :
	Tutti i dati all'interno di una struct sono public, nulla è private ed inoltre non vi è la possibilità di ereditarietà.
	Non consente quindi ereditarietà ed incapsulamento.
	Il modificatore di accesso di default è public.
	
	Calsse(definizione)
		vs
	Oggetti(istanza)
	
	Il responsabile dell'istanziazione dell'oggetto di una determinata classe è il metodo costruttore.
	Esso è un metodo che ha lo stesso nome della classe e nessun tipo di ritorno.
	Una classe ha bisogno di un costruttore per essere istanziata.
	
	Costruttore:
	-	di default: senza parametri 
	-	completo(standard): prende tutti i parametri in input
	- 	copy constructor: copia bit a bit i dati di un oggetto per costruirne uno identico
	
*/

#include<iostream>
using namespace std;

class persona{
	
	string nome = "nome", cognome = "cognome", email = "e-mail";
	int eta = 20;
	int* temperatura;
	
	public:
		persona(){}
		
		persona(string nome, string cognome, int eta, string email){
			this->nome = nome;
			this->cognome = cognome;
			this->eta = eta;
			this->email = email;
			temperatura = new int[100];
		}
		
		persona(const persona& p){
			this->nome = p.nome;
			this->cognome = p.cognome;
			this->eta = p.eta;
			this->email = p.email;
		}
		
	/*	void print(){
			cout<<"Mi chiamo "<<nome<<" "<<cognome<<", ho "<<eta<<" anni e la mia email e' "<<email<<endl<<endl;
		}
	*/
		inline void print();
		//inline vuol dire che il metodo viene incluso nell'istanza dell'oggetto.
		//il codice della funzione viene espanso nel punto della chiamata in fase di compilazione. 
		
		~ persona(){
			delete [] temperatura;
		}
};
	
	//definizione funzione inline
	void persona::print(){
		cout<<"Mi chiamo "<<nome<<" "<<cognome<<", ho "<<eta<<" anni e la mia email e' "<<email<<endl<<endl;
	}

void fun(){
	persona p;
	persona p1("Alfio", "Spoto", 20, "alfio.spoto@outlook.it");
	cout<<"p :"<<endl;
	p.print();
	cout<<"p1 :"<<endl;
	p1.print();
	p = p1;
	cout<<"p :"<<endl;
	p.print();
	cout<<"Adress of &p:\n"<<&p<<"\nAdress of p1:\n"<<&p1<<endl;
}

int main(){
	fun();
	cout<<"Ciao "<<endl;
}