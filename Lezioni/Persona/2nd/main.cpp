#include <iostream>
#include <string>

using namespace std;

#include "persona.cpp"
#include "studente.cpp"

int main(){
	Persona p1("Alfio", "Spoto", 10);
	p1.print();
	int i=0;
	while (i<10)
	{
		p1++;
		i++;	
	}
	cout<<"\n\t....Dopo 10 anni....\n "<<endl;
	p1.print();
	cout<<"-----------------------------------------------------------"<<endl;
	short matricola [10] = {1, 0, 0, 0, 0, 2, 5, 4, 5, 2};
	Studente s ("Alfio", "Spoto", 20, matricola);
	s.print();
	
}