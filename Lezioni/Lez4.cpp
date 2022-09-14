/*

COMPLESSITA'
guardia = if(x % 2 == 0){
corpo 
}
corpo costo preponderante;
la complessità e' la somma del costo di ogni singola istruzione
N e' preponderante rispetto le istruzioni

N
{	Ci
i=0
array N elementi arr[N] = {0,1,2,3,4,5,6} ci metterà di meno rispetto {6,5,4,3,2,1,0}
{0,1,2,3,4,5,6} caso migliore
{6,5,4,3,2,1,0} caso peggiore
{3,1,0,5,6,2,4} caso medio
tutto ciò ha a che fare con il tempo di esecuzione dell' algoritmo

complessità temporale 
* e' proporzionale al numero di operazioni
* indipendente dall'hardware considerato

ASSUNZIONE 2
* dipendenza dalla dimensione dell'input
* comportamento asintotico dell'input N-> ∞

consideriamo
for(i = 0; i<N; i++)
	swap(i,i+1)
	swap(i+2,i+1) {costo 3 
	v[i] = -4;
NON SI VALUTA L'ALGORITMO MA LA DIMENSIONE
O(g(n))) = {f(n) : esiste c, n0}

0<= f(n) <= c*g(n) per ogni n >= n0
f(n) = O(g(n))
f(n) = O(n), O(i); O(log); O(n^2);

FUNZIONI NOTEVOLI
costante f(n) = c;
logaritmica f(n) = log base b con b>=1 di n;
lineare = f(n) = n;
log-lineare = f(n) = n log n;
polinomiale = f(n) = n^c, a > 1;
esponenziale = f(n) = a^n, a > 1;

NOTAZIONE OMEGA
OMEGA (g(n)) = {f(n) : esiste c, n0 tale che 0<= g(n) <= f(n)} qualunque n>= n0
f(n) = OMEGA(g(n));

NOTAZIONE TETA
TETA g(n) = {f(n) : esiste c1, c2, n0 tale che 0<=c1(g(n)) <= f(n) <= c2(g(n)) qualunque n>=0}
f(n) = TETA (g(n)) se e solo se f(n) = OMEGA(g(n)) e f(n) = O(g(n));
c1 limita inferiormente
c2 limita superiormente

#include<iostream>
using namespace std;

void func(int n){
	int count = 0;
	
	for(int i = n/2; i<=n; i++){  //Complessità computazionale: O(n)
		for(int j=1; j<=n; j=2*j){  //Complessità computazionale: O(log n)
			for(int k=1; k<=n; k=k*2){  //Complessità computazionale: O(log n)
				count++;
			}
		}
	}
	
	
	Sistemo le tre complessità moltiplicandole:
		Complessità totale: 
					n * log n * log n
	
}

void func(int n){
	
	for(int i=0; i<=n; i *= c){
		//espressioni con costo 0(1)
	}
	//Complessità: O(log n)
	
	for(int i=0; i<=n; pow(i, c){
		//espressioni con costo 0(1)
	}
	//Complessità: O(log log n)

}

void func(int n){
	
	for(int i=1; i<n; i*=2){  // O(log n)
		for(int j=0; j<n/2; j++){  //  O(n)
			for(int k=j; k<n; k *= 2){  //O(log n)
				O(1);
			}
		}
	}
	Complessità: O(log log n)
}
*/