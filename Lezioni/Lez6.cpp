/*
Ricerca di: 

	3 5 7
	
	- Ricerca sequenziale
	
		5:	1 passo
		7:	3 passi
		3:	9 passi
		-----------------
		5:	10 passo
		7:	7 passi
		3:	5 passi
		-----------------
		5:	2 passo
		7:	1 passi
		3:	4 passi
		
		Complessità 0(n) Lineare
	
	- Ricerca dicotomica (binaria) 
	
		5:	3 passo
		7:	3 passi
		3:	3 passi
		
		Complessità log(n) Logaritmica
			Infatti 3 è circa il log(base 2) di n

Riordinamento:
	
	primo = 5 swap
	secondo = 2 swap
	terzo = 1 swap
	quarto = 1 swap
	quinto = 2 swap
	sesto =  2 swap
	settimo = 2 swap
	ottavo = 1 swap
	nono = 0 swap
	decimo = 0 swap
	
	Complessità O(n)^2


VISUALGO
Selection sort:
	
	Invece di effettuare gli scambi con tutti gli elementi minori vado a cercare il minore e lo scambio.
	L’algoritmo di volta in volta seleziona il numero minore della sequenza e lo sposta nella sequenza
	ordinata.
	
	Complessità O(n)^2
	
Insertion sort:
	
	Un algoritmo di ordinamento che utilizza lo stesso metodo che un essere umano usa per ordinare le sue 
	carte in mano.
	Dunque fa un tipo di ordinamento in loco, ovvero non crea un array di appoggio, risparmiando in questo 
	modo memoria.
	L’algoritmo ha bisogno di due indici, uno che punta all’elemento da ordinare e l’altro a quello 
	immediatamente precedente.
	Il passo successivo consiste nel confrontare i due elementi, se l’elemento puntato dal secondo indice è maggiore 
	del primo gli elementi allora vengono scambiati.
	
	Complessità O(n)^2


Le costanti di applicazione hanno più impatto sul selection sort che sull'insertion sort, quindi anche a parità di 
complessità , è più efficiente l'insertion.
*/

#include<iostream>
using namespace std;

bool ricerca_binaria(int array[], int n, int key){
	//Si assume che l'array sia ordinato
	bool found = false;
	
	int start = 0;
	int end = n;
	int mid_point = start + (end-start)/2;
	
	while(!found && start != end ){
		
	/*	cout<<"Start: "<<start<<endl;
		cout<<"End: "<<end<<endl;
		cout<<"Mid point: "<<mid_point<<endl;*/
		
		mid_point = start + (end-start)/2;

		if(array[mid_point] == key)  //l'elemento è a metà dell'array
			found = true;
			
		else if(key < array[mid_point])  //cerco a sinistra
			end = mid_point;
			
		else if(key > array[mid_point]) //cerco a destra
			start = mid_point;
		
	}
	
	return found;
}

//Versione ricorsiva
bool ricerca_binaria_ricorsiva(int vet[], int n, int key, int start, int end){ 
	
	int mid(start + (end - start)/2);
	
	//CASO BASE
	if(start == end)
		if(vet[mid] == key)
			return true;
		else 
			return false;
		
	//PASSO INDUTTIVO
	if(key == vet[mid])
		return true;
	
	else if(key < vet[mid])
		end = mid-1;
	else
		start = mid +1;
	
	ricerca_binaria_ricorsiva(vet, n, key, start, end);

}

//Algoritmo di ordinamento
void sort(int vet[], int n){
	
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(vet[j] < vet[i]){
				swap(vet[i],vet[j]);
			}
		}
	}
}

int main(){
	
	int array[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	int n = sizeof(array)/sizeof(int);
	/*if(ricerca_binaria(array, 10, 11))
		cout<<"Trovato"<<endl;
	else
		cout<<"Non trovato"<<endl;*/
	
	if(ricerca_binaria_ricorsiva(array, n, 11, 0, n-1))
		cout<<"Trovato"<<endl;
	else
		cout<<"Non trovato"<<endl;
	
}