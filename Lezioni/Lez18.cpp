/*
	Visita in ampiezza di un grafo : Algoritmo BFS(Breadth-First Search)

	Nella teoria dei grafi, la ricerca in ampiezza è un algoritmo di ricerca per grafi che partendo da un vertice 
	detto sorgente permette di cercare il cammino fino ad un altro nodo scelto e connesso al nodo sorgente.

	BFS è un metodo di ricerca non informato, ed ha il suo obiettivo quello di espandere il raggio d'azione 
	al fine di esaminare tutti i nodi del grafo sistematicamente, fino a trovare il nodo cercato. 
	In altre parole, se il nodo cercato non viene trovato, la ricerca procede in maniera esaustiva su tutti i 
	nodi del grafo. 

	Il procedimento da seguire per metterlo in pratica è sintetizzato come segue:

	1.Mettere in coda il "nodo sorgente".

	2.Togliere dalla coda un nodo (nella prima iterazione il nodo sorgente) ed esaminarlo.

		-Se l'elemento cercato è trovato in questo nodo viene restituito il risultato e la ricerca si interrompe.
	 	-Se l'elemento cercato non era in questo nodo mettere in coda tutti i successori non ancora visitati del 
	 	 nodo in analisi.

	3.Se la coda è vuota, ogni nodo nel grafo è stato visitato e l'elemento non è stato trovato perché non presente 
	  e quindi la ricerca si interrompe.

	4.Se la coda non è vuota, ripetere il passo 2.

	Se si volesse restituire l'albero breadth-first sarebbe necessario tenere nota di tutti i nodi visitati e 
	del predecessore tramite il quale si è arrivati a loro. A tale scopo, a seconda dello stadio di elaborazione, 
	sarebbe utile marcare i nodi con delle etichette quali "visitato", "in corso di visita" e "non visitato".

	Al tempo(passo) k avrò visitato tutti i nodi a distanza k dal nodo sorgente.

	--------------------------------------------------------------------------------------------------------------

	Visita in profondità di un grafo : Algoritmo DFS (Depth-First Search)

	Nella teoria dei grafi, la ricerca in profondità, è un algoritmo di ricerca su alberi e grafi. 
	A differenza della ricerca in ampiezza, ha la caratteristica di essere intrinsecamente ricorsivo.

	La visita di s procede come segue:

	• Si visitano ricorsivamente tutti i vertici adiacenti ad s;
	• Si termina la visita del vertice s e si ritorna.

	Bisogna evitare di rivisitare vertici già visitati
	• Bisogna anche qui evitare i cicli
	• Nuovamente, quando un vertice è stato scoperto e (poi) visitato viene marcato opportunamente (colorandolo)

	Manterremo traccia del momento (tempo) in cui ogni vertice v viene scoperto e del momento in cui viene visitato.
	Useremo inoltre due array d[v] e f[v] che registrano il momento in cui v verrà scoperto e quello in cui verrà 
	visitato.
	La variabile globale tempo serve a registrare il passaggio del tempo.

	Tenere traccia del tempo serve all'ordinamento topologico del grafo.
	Si tratta di un ordinamento inverso rispetto alla visita in profondità.

*/

#include<iostream>
using namespace std;

int main(){

	/*Il Discovery time:

		nel BFS indica la distanza dal sorgente
		nel DFS indica l'ordinamento topologico del grafo*/

	//PSEUDOCODICE BFS

	//INIZIALIZZAZIONE
	BFS(G, s);
		for ogni vertice u nel grafo G:
			color[u] = white
			d[u] = inf //tempo di discovery
			p[u] = null //pi greco, il predecessore
		color[s] = gray
		p[s] = null
		d[s] = 0

	//VISITA
	Q = empty //la coda all'inizio è vuota
	Q.enqueue(s)
	while(Q != empty)
		u.dequeue() //la prima iterazione è il sorgente
		for ogni vertice in adj[u] //nella lista di adiacenza di u
			if(color[v] == white)
				color[v] = gray
				d[v] = d[u] + 1
				p[v] = u
				Q.enqueue(v)
		color[u] = black

	/*
		Computazionalmente la visita pesa molto più dell'inizializzazione.

		Q = empty 
		Q.enqueue(s)
		while(Q != empty) //O(|V|) perchè è al massimo il numero dei vertici
			u.dequeue() 
			for ogni vertice in adj[u] //O(|E|) perchè prende al massimo il numero dei nodi adiacenti 
												(dipende dal numero di archi) ed è associato all'intero grafo.
												Quindi al massimo farò |E|/|V|passi

				if(color[v] == white)
					color[v] = gray
					d[v] = d[u] + 1
					p[v] = u
					Q.enqueue(v)
			color[u] = black

		La complessità del while e del for interno si somma perchè il costo del while è associato ai vertici
		mentre il costo del for è associato all'intero grafo, non ad ogni singolo nodo.

		Complessità totale del BFS -> O(|E|) + O(|V|)
	*/

	//PSEUDOCODICE DFS

	DFS(G)
		for ogni vertice u in G
			color[u] = white
			d[u] = 0 //discovery
			f[u] = inf //finish
			p[u] = null
		global time = 0
		for ogni vertice u in G
			if color[u] == white
				DFS-visit(u)

	DFS-visit(u)
		color[u] = gray
		time++
		d[u] = time
		for v in adj[u]
			if color[u] == white
				p[v] = u
				DFS-visit(v)
		color[u] = black
		time++
		f[u] = time

	/*
		Computazionalmente la visita pesa molto più dell'inizializzazione.

		DFS(G)
			for ogni vertice u in G //costo O(|V|)
				color[u] = white
				d[u] = 0 //discovery
				f[u] = inf //finish
				p[u] = null
			global time = 0
			for ogni vertice u in G
				if color[u] == white
					DFS-visit(u)

		DFS-visit(u)
			color[u] = gray
			time++
			d[u] = time
			for v in adj[u] //costo O(|E|)
				if color[u] == white
					p[v] = u
					DFS-visit(v)
			color[u] = black
			time++
			f[u] = time

		La complessità del while e del for interno si somma perchè il costo del while è associato ai vertici
		mentre il costo del for è associato all'intero grafo, non ad ogni singolo nodo.

		Complessità totale del DFS -> O(|E|) + O(|V|)
	*/
}