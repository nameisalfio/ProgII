#ifndef SORTING_H
#define SORTING_H

void print(int vet[], int n){
    
    cout << "\nArray: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << vet[i] << "\t";
    }
    cout << endl;
}

//Importante il passsaggio per riferimento
void swap(int& a, int& b){
    int temp = a;
    a = b;
    b = temp;
}

//Algoritmi di ricerca
//---------------------

//Ricerca sequenziale(lineare)		Complessità 0(n) Lineare
void search(int vet[], int n, int key){
    
    cout << "\nRicerca lineare" << endl;

    int iter = 0;
    for(int i=0; i<n; i++)
    {
        iter++;
        if(vet[i] == key)
        {
            cout << "Trovata alla " << iter << "° iterazione" << endl;
            return;
        }
    }

    cout << "Chiave non trovata! " << endl;
}

//Ricerca binaria(dicotomica)		Complessità 0(log n) logatirmica
void binary_search(int vet[], int n, int key){

    cout << "\nRicerca binaria" << endl;
    //Si assume che l'array sia ordinato
    int iter = 0;

    //indici
    int start = 0;
    int end = n;
    int middle = start+(end-start)/2;

    bool found = false;

    while(!found && start != end)
    {
        middle = start+(end-start)/2;

        iter++;
        if(vet[middle] == key)
            found = true;

        if(key < vet[middle]) //cerco a sx
            end = middle;

        if(key > vet[middle]) //cerco a dx
            start = middle;

    }
    
    if(!found)
        cout << "Chiave non trovata! " << endl;
    else
        cout << "Trovata alla " << iter << "° iterazione" << endl;
}

//Versione ricorsiva		        Complessità 0(log n) logatirmica
void binary_search_ricorsive(int vet[], int n, int key, int iter, int start, int end){

    //Si assume che l'array sia ordinato

    int middle = start+(end-start)/2;
    iter++;

    if(vet[middle] == key)
    {
        cout << "Trovata alla " << iter << "° iterazione" << endl;
        return;
    }

    if(start == end && vet[middle] != key)
       cout << "Chiave non trovata! " << endl;

    if(key < vet[middle]) //cerco a sx
        binary_search_ricorsive(vet, n, key, iter, start, middle);

    if(key > vet[middle]) //cerco a dx
        binary_search_ricorsive(vet, n, key, iter, middle, end);

}

void binary_search_ricorsive(int vet[], int n, int key){
    cout << "\nRicerca binaria con ricorsione: " << endl;
    int iter = 0;
    int start = 0;
    int end = n;
    return binary_search_ricorsive(vet, n, key, iter, start, end);
}


//Algoritmi di riordinamento
//---------------------

//Selection sort                    Complessità O(n)^2 in qualunque caso
void selection_sort(int vet[], int n){

    for(int i=0; i<n; i++)
    {
        int idx=i;
        for(int j=i+1; j<n; j++) //Scorro il sotto-array non ordinato 
        {
            if(vet[j] < vet[idx]) //Conservo l'indice dell'elemento minimo
                idx = j;
        }
        swap(vet[i], vet[idx]);
    }
}

//Insertion sort                    Complessità O(n)^2 nel caso medio e peggiore
void insertion_sort(int vet[], int n){

    int temp;
    for(int i=1; i<n; i++)
    {
        temp = vet[i];
        int j;
        for(j=i-1; j>0; j--) //scorro la partizione di sx
        {
            if(temp < vet[j])
                vet[j] = vet[j-1]; //sposto tutti gli elementi nella partizione ordinata in avanti
            else 
                break;
        }
        vet[j] = temp;
    }
}
/*Possiamo migliorare l’insertion sort utilizzando la ricerca binaria
per collocare correttamente l’elemento a[i] nel sottoarray
ordinato.*/

//Bubble sort                       Complessità O(n)^2 in qualunque caso
void bubble_sort(int vet[], int n){
    
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++) //Confronta gli elementi adiacenti
        {
            if(vet[j] < vet[i])
                swap(vet[j], vet[i]); //Fa "risalire" quelli più leggeri
        }
    }

}
//Dopo n-1 iterazioni l’array risulterà ordinato

//Algoritmi di riordinamento RICORSIVI
//---------------------

//Merge sort                        Complessità totale : O(n log n) in ogni caso

//Procedura Merge per la combinazione
void merge(int vet[], int start, int middle, int end)
{
    int i = start;
	int j = middle +1;
	int k = start;
	int aux[end+1]; //vettore ausiliario di dimensione n

    while(i <= middle && j <= end)
    {
        if(vet[i] <= vet[j]) //Inserisco in auxl'elemento minore delle partizioni ordinate
            aux[k++] = vet[i++];
        else
            aux[k++] = vet[j++];
    }

    //Se "consumo" una delle due partizioni devo inserire in ordine tutti gli elementi dell'altra
    while(i <= middle)
        aux[k++] = vet[i++];

    while(j <= end)
        aux[k++] = vet[j++];

    for(k = start; k <= end; k++) //Copio i valori nell'array di partenza
		vet[k] = aux[k];
}

//Algoritmo di suddivisione
void merge_sort(int vet[], int start, int end){
	
    if(start < end) //Se c'è più di un elemento
    {
        int middle = floor((start+end)/2);
        merge_sort(vet, start, middle);
        merge_sort(vet, middle+1, end);
        merge(vet, start, middle, end);
    }
}

void merge_sort(int vet[], int n){
    //Richiamo passando il vettore, l'indice del primo e dell'ultimo elemento
    merge_sort(vet, 0, n-1);
}


//Quick sort                        COmplessità totale : 0(n log n) in ogni caso

//Procedura Partition che effettua la partizione e restituisce la posizione del pivot
int partition(int vet[], int start, int end){

    int pivot = vet[end]; //scelgo l'ultimo elemento come pivot
    int i = start-1;  //Indice del minimo corrente all'interno della lista

    for(int j=start; j<end; j++)//J è l'indice dell'elemento corrente preso in esame
	{
		if(vet[j] <= pivot)
		{
			i++; //lo aggiorno solo se trovo un elemento minore del pivot
			swap(vet[i], vet[j]);
		}
	}
	swap(vet[i+1], vet[end]);  //posiziono correttemente il pivot e lo restituisco

	return i+1;
}

void quick_sort(int vet[], int start, int end){

    if(start < end) //Se c'è più di un elemento
	{
		int pivot = partition(vet, start, end); //setto il pivot
		quick_sort(vet, start, pivot-1); //riordino la partizione di sx
		quick_sort(vet, pivot+1, end);  //riordino la partizione di dx
	}

}

void quick_sort(int vet[],int n){
    //Richiamo passando il vettore, l'indice del primo e dell'ultimo elemento
	quick_sort(vet, 0, n-1);
}


#endif