#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <limits.h>
#include <math.h>
using namespace std;

/*int main(){
	
	int array1 [100];
	//Struttura dati contenente elementi tutti dello stesso tipo
	//che vengono allocati in celle di memoria contigue e indicizzate
	
	int array2[]={10,10,10,10};
	cout<<sizeof(array1)<<endl;
	cout<<sizeof(array2)<<endl;
	cout<<"Massimo char : "<<CHAR_MAX<<endl;
	int n_array2 = sizeof(array2)/sizeof(int);
	cout<<"Lunghezza array2 : "<<n_array2<<endl;
	cout<<"Array1: "<<endl;
	for(int i=0; i<100; i++)
	{
		array1[i] = i+1;
		cout<<"\t"<<array1[i]<<endl;
	}
	for(int i=0; i<n_array2; i++)
		cout<<"\t"<<array2[i]<<endl;
	//-----------------------------------
	int* array3 = new int [100];
	cout<<"Dimensione array3: "<<sizeof(array3[0])*100<<endl;
	cout<<"Array3: "<<endl;
	for(int i=0; i<100; i++)
	{
		array3[i] = i+1;
		cout<<"\t"<<array3[i]<<endl;
	}
	
	delete [] array3;  //Evita memory leak
	//Non perdo la variabile ma la rendo sovrascrivibile
	
	cout<<array3<<endl;
	cout<<array3[10]<<endl;
}*/


/*ESERCIZIO 1:
Scrivere un programma che sfrutta un metodo 'leggiElementi()' per 
inizializzare un array di double di dimensione non nota, chiedendo
all'utente di inserire un valore per volta fino a quando non viene
inserito il valore zero. Successivamente, stampare gli elementi
mediante un altro metodo 'stampaElementi()'. */
/*
#define n 100

void leggiElementi(double* vet, int& c){
	
	cout<<"Indirizzo c in leggiElementi: "<<&c<<endl;
	c=0;
	double temp;
	for(int i=0; i<n; i++)
	{
		cout<<"Inserisci un elemento (0 per terminare l'inserimento): "<<endl;
		cin>>temp;
		if(temp == 0)
			break;
		else
			vet[i] = temp;
			c++;
	}
}

void stampaElementi(double* v, int c){
	for(int i=0; i<c; i++)
		cout<<"Elemento n"<<i<<" :"<<v[i]<<endl;
	
	cout<<endl;
}

int main(){
	double vet[n];
	int c;
	cout<<"Indirizzo c nel main: "<<&c<<endl;
	leggiElementi(vet, c);
	stampaElementi(vet, c);
}
*/

/*ESERCIZIO 2:
Definire un metodo che stampa i numeri primi fino ad n;

Vengono presentati 3 metodi:

1) dato num in [2, n] cerco un suo divisore in [2, num/2] se non lo trovo allora
   num è primo;
2) dato num in [2, n] cerco un suo divisore in [2, sqrt(num)] se non lo trovo allora
   num è primo;
3) Crivello di Eratostene o metodo del setaccio.
   Per ogni num in [2, n] elimino i suoi multipli, quelli che rimangono sono primi;*/

void numeri_primi1(int vet[], int& count, int n){
	
	count=0;
	
	for(int i=2; i<= n; i++)
	{
		bool is_prime = true;
		for(int j=2; j<= i/2; j++)
		{
			if(i%j == 0)
			{
				is_prime = false;
				break;
			}	
		}
		if(is_prime)
			vet[count++] = i;
			//cout<<i<<" is prime!"<<endl;
	}
}

void numeri_primi2(int vet2[], int& count2, int n){
	
	count2 = 0;
	
	for(int i=2; i<=n; i++)
	{
		bool is_prime = true;
		for(int j=2; j<=sqrt(i); j++)
		{
			if(i%j == 0)
			{
				is_prime = false;
				break;
			}
		}
		if(is_prime)
			vet2[count2++] = i;
	}
}

void crivello_Eratostene(int vet3[], int& count3, int n){

    count3 = 0;

    for(int i=2; i<=n; i++)
    {
        bool is_prime = true;
        for(int j=2; j<i; j++)
        {
            if(i % j == 0)  //i è multiplo di j
            {
                is_prime = false;
                break;
            }
        }
        if(is_prime)
            vet3[count3++] = i;
    }
}

int main(){
	
	int vet[100];
	int count;
	numeri_primi1(vet, count ,500);
	cout<<"Prima funzione: "<<endl<<"50 numeri primi minori di 500: "<<endl;
	for(int i=0; i<50; i++)
		cout<<vet[i]<<" ";
	
	//--------------------------------------------
	
	int vet2[100];
	int count2;
	numeri_primi2(vet2, count2, 500);
	cout<<"\n\nSeconda funzione: "<<endl<<"50 numeri primi minori di 500: "<<endl;
	for(int i=0; i<50; i++)
		cout<<vet2[i]<<" ";
	
	//--------------------------------------------
	
	int vet3[100];
	int count3 ;
	crivello_Eratostene(vet3, count3, 500);
	cout<<"\n\nTerza funzione: "<<endl<<"50 numeri primi minori di 500: "<<endl;
	for(int i=0; i<50; i++)
		cout<<vet3[i]<<" ";
}