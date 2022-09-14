#include "persona.h"

#include<iostream>
using namespace std;
	
persona::persona(){}
		
persona::persona(string nome, string cognome, int eta, string email){
	this->nome = nome;
	this->cognome = cognome;
	this->eta = eta;
	this->email = email;
	temperatura = new int[100];
}
		
persona::persona(const persona& p){
	this->nome = p.nome;
	this->cognome = p.cognome;
	this->eta = p.eta;
	this->email = p.email;
}

void persona::print(){
	cout<<"Mi chiamo "<<nome<<" "<<cognome<<", ho "<<eta<<" anni e la mia email e' "<<email<<endl<<endl;
}

~ persona:: persona(){
	delete [] temperatura;
}