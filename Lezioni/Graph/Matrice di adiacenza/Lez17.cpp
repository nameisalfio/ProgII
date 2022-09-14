/*
	Grafi

	Un insieme di nodi V detti vertici connessi da collegamenti chiamati archi facenti parte di un insieme E.

	G = (V,E)

	E : VxV->R

	|V| = numero vertici
	|E| = numero archi
	Grafo sparso = |E| << |V|^2
	Grafo denso = |E| circa |V|^2

	Un nodo vi si dice "adiacente" ad un nodo vj se esiste un arco (vi,vj) che li collega.
	In un grafo non orientato se A è un nodo adiacente ad un nodo B, allora anche B è adiacente ad A.
	Non vale lo stesso per gli archi orientati. 

	La rappresentazione avviene tramite "matrici di adiacenza". Queste matrici sono n x n dove n = |V|.
	Nelle matrici di adiacenza abbiamo un valore diverso da 0 nella casella (i,j) se c'è un arco da i a j.
	Nel caso di grafi non orientati ovviamente la matrice è simmetrica.
	Nel caso di grafi orientati la matrice invece non è simmetrica.

	Spazio richiesto in memoria -> |V|^2


	Un altra rappresentazione(più indicata per grafi sparsi) è quella delle "liste di adiacenza", dove
	vengono indicati solo i vertici adiacenti al nodo.

	Spazio richiesto in memoria 
	-Grafo orientato: 2|E|
	-Grafo non orientato: |E|

*/

#include<iostream>
#include "graph.h"

using namespace std;

int main(){

	Graph<int> g(10);

	g.add_vertex(0);
	g.add_vertex(1);
	g.add_vertex(2);
	g.add_vertex(3);

	g.add_edge(0,1);
	g.add_edge(1,2);
	g.add_edge(2,3);
	g.add_edge(0,3);

	cout << g << endl;
	g.print_adj();
}