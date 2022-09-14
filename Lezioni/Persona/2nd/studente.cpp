#include "studente.h"
#include "persona.h"
using namespace std;

Studente :: Studente(string nome, string cognome, int eta, short* matricola) : Persona(nome, cognome, eta){
	for(int i=0; i<10; i++)
		this->matricola[i] = matricola[i];
}

Studente :: Studente(const Studente& s){
	for(int i=0; i<10; i++)
		this->matricola[i] = s.matricola[i];
}

Studente :: Studente(){}

void Studente::print(){
	Persona::print();
	cout<<"La mia matricola e': ";
	print_matricola();
}

void Studente :: print_matricola(){
	for(int i=0; i<10; i++)
		cout<<matricola[i];
	cout<<endl;
}