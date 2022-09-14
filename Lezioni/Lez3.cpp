/*
- Torri di Hanoi
- Ricorsione  
	Una funzione ricorsiva causa un overhead(sovraccarico) che le porta ad essere più lente delle funzioni 
	iterative.Infatti, la ricorsione genera una quantità enorme di overhead, occupando lo stack per un 
	numero di istanze pari alle chiamate della funzione.

1)	Induzione matematica :
	Successore di un numero n:
	-	vale 1 se n=0 (Base dell'induzione)
	-	vale 1 + successore(n-1) (Passo dell'induzione)
	
		ex. succ(3) = 1 + succ(2) = 1 + 3 = 4
		
2)  Somma tra due numeri naturali :
	Somma(a, b)
	-   vale a se b=0 (Base dell'induzione)
	-	vale somma 1+somma(a, b-1) se b>0 (Passo dell'induzione)
	
3)  Prodotto tra due numeri naturali :
	Prod(a, b)   a,b != 0
	-   vale a se b=1 (Base dell'induzione)
	-	vale a + prod(a, b-1) se b>0 (Passo dell'induzione)
	
4)  Potenza tra due numeri naturali : 
	Pow(a^b) a,b != 0
	-	vale a se b=1
	-   vale a * pow(a, b-1)
	
5) Fattoriale di un numero naturale : 
   Fatt(n) 
   -	vale 1 se n=0;
   -    vale n*fatt(n-1) n>0;
  
6) Fibonacci :
	Fib(n)
	-	vale 1 se n=0 o n=1;
	-	vale fib(n-1) + fib(n-2) se n>1;
*/

#include<iostream>
using namespace std;

int succ(int a){
	
	if(a==0)
		return 1;
	else
		return 1 + succ(a-1);
}

int somma(int a , int b){

	if(b==0)
		return a;
	else
		return 1 + somma(a, b-1);

}

int prod(int a, int b){
	
	if(b == 1)
		return a;
	else 
		return a + prod(a, b-1);
	
}

int pow (int a, int b){
	
	if(b==1)
		return a;
	else
		return a*pow(a, b-1);
}

int fatt(int n){
	
	if(n==0)
		return 1;
	else
		return n * fatt(n-1);
}

int fib(int n){
	if(n==0 || n==1)
		return 1;
	else
		return fib(n-1) + fib(n-2);
}

int fib_ite(int n){
	
	int sum1=1;  //somma fino a n-1
	int sum2=1;  //somma fino a n-2
	int x;
	
	if(n==0 || n==1)
		return 1;
	
	for(int i=2; i<=n; i++)
	{
		x = sum2;
		sum2 = sum1;
		sum1 = x + sum2;
	}
	return sum1;
}

int main(){
	
	int a = 2;
	int b = 3;
	cout<<"Successore : "<<succ(a)<<endl;
	cout<<"Somma : "<<somma(a, b)<<endl;
	cout<<"Prod : "<<prod(a, b)<<endl;
	cout<<"Potenza : "<<pow(a, b)<<endl;
	cout<<"Fattoriale : "<<fatt(b)<<endl;
	cout<<"Fibonacci : "<<fib(somma(a, b))<<endl;
	cout<<"Fibonacci iterativo: "<<fib_ite(somma(a, b))<<endl;
	
}

