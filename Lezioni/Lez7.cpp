/*
	In termini di complessità anche se l'insertion sort e il selection sort hanno entrambi complessità
	O(n^2) , si ha che l'insertion è comunque più efficente per via del minore costo delle costanti 
	applicative nascoste all'interno del ciclo.
	
	Algoritmi di ordinamento Ricorsivi
	
	DIVIDE ET IMPERA
	1) Suddividere il problema di partenza in sottoproblemi più semplici da trattare 
	2) Risolvere i sottoproblemi in maniera indipendente
	3) Combinare le soluzioni al fine di risolvere il problema di partenza
	
	La suddivisione del problema è ripetuta fino a trovare un caso base semplice da risolvere.
	
	Passo 1:
		Spezzare l'array fino ad ottenere un sottoproblema di dimensione 1 (un elemento è sempre ordinato).
	
	Passo 2:
		Nel caso base non devo fare nulla.
	
	Passo 3:
		Combinare le soluzioni(cuore dell'algoritmo).
		
	Merge sort:
	
	Il merge sort è un algoritmo di ordinamento basato su confronti che utilizza un processo di risoluzione
	ricorsivo, sfruttando la tecnica del Divide et Impera, che consiste nella suddivisione del problema 
	in sottoproblemi della stessa natura di dimensione via via più piccola.
	
	- 1 problema di dimensione N
	- N problemi di dimensione 1
	
	Concettualmente, l'algoritmo funziona nel seguente modo:

	Se la sequenza da ordinare ha lunghezza 0 oppure 1, è già ordinata. Altrimenti:
	La sequenza viene divisa (divide) in due metà (se la sequenza contiene un numero dispari di elementi,
	viene divisa in due sottosequenze di cui la prima ha un elemento in più della seconda).
	Ognuna di queste sottosequenze viene ordinata, applicando ricorsivamente l'algoritmo (impera).
	Le due sottosequenze ordinate vengono fuse (combina). 
	Per fare questo, si estrae ripetutamente il minimo delle due sottosequenze e lo si pone nella sequenza
	in uscita, che risulterà ordinata.
	
	p = indice di inizio sottoarray
	r = indice fine sottoarray
	q = indice di fine primo e inizio secondo
	
	p <= q <= r
	
	n1 = q-p+1
	n2 = r-q
	
	Creo due sottoarray L(dim.n1) ed R(dim.n2)
	Ho un indice k che scorre l'array principale A
	Ho un indice i che scorre l'array L
	Ho un indice j che scorre l'array R
	
	for(k = p...r; i = 1...n1; j = 1...n2)
	{
		if L[i] <= R[j]
			A[k] = L[i]
			i++
		else
			A[k] = R[j]
			j++
		k++
	}
	
	In L ed R ho n/2 elementi con n = dimensione del problema iniziale. La procedura merge richiede sempre 
	tempo n o meglio Teta(n). Limite asintotico superiore e inferiore. Avendo tempo minore o uguale ad
	n , e non minore stretto , si ha una complessotà Teta e non O grande.
	
	Complessità Teta(n)log n
	
	Merge_sort(A, p, r){} p-->indice inizio e r-->indice fine
	
	Merge_sort(A, p, q, r) 
	- p ed r sono parametri
	- q lo calcolo
	
	if(p<r)
		q = floor ( (p + r) /2 )
		Merge_sort(A, p, q) //Riordino a sx
		Merge_sort(A, q+1, r) //Riordino a dx
		
		Merge(A, p, q, r) //Unisco le soluzioni
		
	
	M_S(A, 0, 7)
	
	q=floor((7+0)/2)
	
	M_S(A, 0, 3) //SX
		q=1
		M_S(A, 0, 1) //SX
		q=0
		M_S(A, 0, 0) //SX
		
		q=1
		M_S(A, 1, 1) //DX
		
		M_S(A, 2, 3) //DX
		q=2
		M_S(A, 2, 2) //SX
		
		q=3
		M_S(A, 3, 3) //DX
		
		M_S(A, 0, 1, 3) //MERGE
		
	M_S(A, 4, 7) //DX
		q=5
		M_S(A, 4, 5) //SX
			q=4
			M_S(A, 4, 4) //SX
			
		M_S(A, 6, 7) //DX
			q=6
			M_S(A, 6, 6)
			M_S(A, 7, 7)
			
		M_S(A, 4, 5, 7) //MERGE
		
	M_S(A, 0, 3, 7) //MERGE
	
	La creazione di due array ausiliari causa un'incremento della complessità spaziale, anche se non 
	temporale , dell'algoritmo.Sostanzialmente si necessita del doppio della memoria che occuperebbe
	l'input iniziale.


	Quick sort :
	Lavora sul posto e non ha bisogno di array di appoggio come il Merge sort.
	Quicksort è un algoritmo di ordinamento ricorsivo in place non stabile. Tale procedura ricorsiva 
	viene comunemente detta partition: preso un elemento chiamato "pivot" da una struttura dati si 
	pongono gli elementi minori a sinistra rispetto al pivot e gli elementi maggiori a destra.
	
	Si effettua la scelta di un elemento nell'array , chiamato Pivot. Tendenzialmente il pivot è sempre
	l'ultimo elemento dell'array. 
	
	i = p-1
	j = p
	r = fine array
	
	Far scorrere j da p a r-1 e se l'elemento A[j] <= pivot allora faccio avanzare i e scambio A[i] con 
	A[j]. Faccio avanzare j altrimenti.
	
	Di volta in volta gli elementi a sx di A[i](compresa) saranno minori di pivot e quelli a destra di 
	A[j] saranno maggiori di pivot. Alla fine scambio il pivot con A[i+1] quindi otterrò alla sinistra 
	del pivot tutti gli elementi minori di se stesso e a dx quelli maggiori.
	Alla fine restituisco i+1, ovvero la posizione finale del pivot.
	
	Quicksort(A, p, r)
	if(p<r)
		q = partition(A, p, r)
		Quicksort(A, p, q-1) //call A
		Quicksort(A, p+1, r) //call B
	
	Complessità
	
	Se il pivot non è troppo vicino all'elemento massimo o minimo la complessità del Quicksort 
	è O(n(log n));
	
	Se il pivot dovesse capitare in prossimità di uno dei due estremi (max o min) la complessità
	diventa quadratica O(n^2);
	
	Considerazioni:
	
	La scelta del pivot è casuale, cioè non stiamo facendo alcuna considerazione sul suo valore 
	effettivo.L'algoritmo ritorna la posizione finale del pivot.
	
*/


