#ifndef STUDENTE_H
#define STUDENTE_H

class Studente : public Persona{
	
		short matricola[10];
	
	public:
		Studente(string, string, int, short[]); //Standard constructor
		Studente(const Studente&); //copy constructor
		Studente(); //empty constructor
		void print()override;
		
	protected:
		void print_matricola();
};

#endif