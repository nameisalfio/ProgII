#include <iostream>
#include<math.h>
using namespace std;

void print (int vet[], int n){
	for(int i=0; i<n; i++)
		cout<<vet[i]<<"\t";
	cout<<endl;
}


void swap (int& a, int& b){
	int aux = a;
	a = b;
	b = aux;
}

//---------------------------------------------------------------------------------------------

void selection_sort(int vet[], int n){
	
	short index = 0;
	
	for(int i=0; i<n; i++){
		index = i;
		for(int j=i+1; j<n; j++){
			if(vet[j] < vet[index]){
				index = j;
			}
		}
		swap(vet[i],vet[index]);
	}
}

//---------------------------------------------------------------------------------------------

void bubble_sort(int vet[], int n){
	
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			if(vet[j] < vet[i]){
				swap(vet[j],vet[i]);
			}
		}
	}
}

//---------------------------------------------------------------------------------------------

void insertion_sort(int vet[], int n){
    for(int i=1; i<n; i++)
    {
        int temp = vet[i];
        int j;
        for(j=i-1; j>=0; j--) //scorro la partizione di sx
        {
            if(temp < vet[j])
                vet[j+1] = vet[j];  //sposto tutti gli elementi della partiz. ordinata in avanti
            else 
                break;
        }
        vet[j+1] = temp;
    }
}
//---------------------------------------------------------------------------------------------

void merge(int vet[], int p, int q, int r){
	
	int i = p;
	int j = q +1;
	int k = p;
	int aux[r+1];

	while(i<= q && j<= r){
		if(vet[i] <= vet[j]){
			aux[k] = vet[i];
			i++;
		}
		else {
			aux[k]= vet[j];
			j++;
		}
		k++;
	}

	while(i<=q){
		aux[k] = vet[i];
		i++;
		k++;
	}

	while(j<=r){
		aux[k] = vet[j];
		j++;
		k++;
	}

	for(k=p;k<=r;k++)
		vet[k] = aux[k];
}

void merge_sort(int vet[], int p, int r){
	
	if(p < r){  //Se c'è più di un elemento 
		int q = floor((r+p)/2);  //indice di mezzo
		merge_sort(vet, p, q); //ordino la partizione di sx
		merge_sort(vet, q+1, r); //ordino la partizione di dx
		merge(vet, p, q, r); //combino le due partizioni precedentemente ordinate
	}
}

//---------------------------------------------------------------------------------------------
int partition(int vet[], int p, int r){ //lista, primo indice e ultimo indice

	int pivot = vet[r];
	int i = p-1;  //Indice del minimo corrente all'interno della lista

	for(int j=p; j<r; j++)//J è l'indice dell'elemento corrente preso in esame
	{
		if(vet[j] <= pivot)
		{
			i++;
			swap(vet[i], vet[j]);
		}
	}
	swap(vet[i+1], vet[r]);  //posiziono correttemente il pivot e lo restituisco
	return i+1;

}

void quick_sort(int vet[], int p, int r){

	if(p < r)  //caso base
	{
		int pivot = partition(vet, p, r); //setto il pivot
		quick_sort(vet, p, pivot-1); //partizione di sx
		quick_sort(vet, pivot+1, r);  //partizione di dx
	}

}

void quick_sort(int a[],int dim){
	quick_sort(a, 0, dim-1);
}





