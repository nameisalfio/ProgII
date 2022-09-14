#include<iostream>
#include<limits.h>
#include<stdlib.h>
#include<math.h>
using namespace std;

//#include "sorting.h"

void print (int vet[], int n){
	for(int i=0; i<n; i++)
		cout<<vet[i]<<"\t";
	cout<<endl;
}

void swap (int a, int b){
	int aux = a;
	a = b;
	b = aux;
}

void merge(int A[], int p, int q, int r){
	
	int n1 = q-p+1;
	int n2 = r-q;
	cout<<"Indici: "<<p<<" "<<q<<" "<<r<<endl;
	int* L = new int [n1+1];
	int* R = new int [n2+1];
	
	for(int i=0; i<n1; i++)//sx
		L[i] = A[p+i];
	
	for(int j=1; j<=n2; j++)//dx
		R[j-1] = A[q+j];
	
	//L'elemento sentinella serve per non andare a leggere un elemento fuori dall'array
	L[n1] = INT_MAX;
	R[n2] = INT_MAX;
	
	int i=0, j=0, k=p;
	
	for(int k=p; k<=r; k++)
	{
		if(L[i] < R[j])
		{
			A[k] = L[i];
			i++;
		}else
		{
			A[k] = R[j];
			j++;
		}
	}
	
	//delete L ; Perdo il riferimento al primo elemento
	delete [] L;
	delete [] R;
}

void merge_sort(int vet[], int p, int r){
	
	if(p < r){  //Se c'è più di un elemento 
		int q = (r+p)/2;  //indice di mezzo
		merge_sort(vet, p, q); //odrino la partizione di sx
		merge_sort(vet, q+1, r); //ordino la partizione di dx
		merge(vet, p, q, r); //combino le due partizioni precedentemente ordinate
	}
}


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

int main(){
	
	int array[10] = {8, 4, 10, 2, 7, 6, 5, 1, 9, 3};
	int n = sizeof(array)/sizeof(int);
	print(array, n);
	
/*	
	merge_sort(array, 0, n-1);
	cout<<endl<<"Merge sort"<<endl;
	print(array, n);
	
*/
	quick_sort(array, n);
	cout<<endl<<"Quick sort"<<endl;
	print(array, n);

}