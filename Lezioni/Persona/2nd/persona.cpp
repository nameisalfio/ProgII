#include "Persona.h"

Persona :: Persona(string nome, string cognome, int eta){
	this->nome = nome;
	this->cognome = cognome;
	this->eta = eta;
}

Persona :: Persona(){}

Persona :: Persona(const Persona& p){
	this->nome = p.nome;
	this->cognome = p.cognome;
	this->eta = p.eta;
}

void Persona::print(){
	cout<<"Mi chiamo "<<nome<<" "<<cognome<<", ho "<<eta<<" anni "<<endl;
}

Persona Persona::operator++ (int){
	Persona temp = *this;
	eta++;
	return temp;
}