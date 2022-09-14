#include "persona.cpp"
#include "persona.h"

#ifndef STUDENTE_H
#define STUDENTE_H

class studente : persona(){
	
	string matricola;
	
	public:
		studente() : persona() {}
		studente(string nome, string cognome, int eta, string email):persona(n, c, e, email){}
		studente(const studente& s){
			this->matricola = s.matricola;
			temperatura = new int[100];
		}
		
		void print(){
			persona::print();
			cout<< "\nLa mia matricola : "<<matricola<<endl;
		}
};

#endif