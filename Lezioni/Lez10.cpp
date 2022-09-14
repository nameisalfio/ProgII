#include<iostream>
#include<cstdlib>
#include<ctime>
#include<string>
#include<cmath>

using namespace std;

/*
Di default il copy constructor effettua una "Shallow Copy".
Questa copia consiste nel copiare tutti i campi valore ma non si effettua la copia dei puntatori 
contenuti nella classe. 

Keyword "Static"
Estende llo scope di visibilità di una variabile contenuta in un metodo della classe e la rende visibile
all'interno delle funzioni esterne che la richiamano. La variabile non viene distrutta all'uscita del 
corpo della funzione. Static garantisce che l'inizializzazione della variabile avviene una ed una 
sola volta, anche se venisse richiamata più volte.
*/

void fun_non_static (){
	int a = 10;
	cout<<"Non-static function a="<<a<<endl;
	a++;
}

void fun_static (){
	static int a = 10;
	cout<<"Static function a="<<a<<endl;
	a++;
}



int main(){
	
	for(int i=0; i<=10; i++)
		fun_non_static ();
	
	cout<<endl;
	
	for(int i=0; i<=10; i++)
		fun_static();

}