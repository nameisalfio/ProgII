#ifndef PERSONA_H
#define PERSONA_H

class Persona{

		string nome = "Nome";
		string cognome = "Cognome";
		int eta = 20;
	
	public:
		Persona(string, string, int);
		Persona(const Persona& );
		Persona();
		virtual void print();
		Persona operator++ (int);
};

#endif