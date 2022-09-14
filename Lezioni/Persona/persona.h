#ifndef PERSONA_H
#define PERSONA_H

#include "persona.h"

#include<iostream>
using namespace std;

class persona{
	
	string nome = "nome", cognome = "cognome", email = "e-mail";
	int eta = 20;
	int* temperatura;
	
	public:
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
};

#endif