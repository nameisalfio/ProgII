/*
#include<iostream>
using namespace std;

class Base {
	
	protected:
		int n = 10;
};

class Derivata1 : protected Base{
};

class Derivata2 : protected Base{
	public:
		Base::n;
};

int main(){
	Derivata1 d1;
	Derivata2 d2;
	//cout<<d1.n<<endl; ERRORE
	cout<<d2.n<<endl;
}
*/

/*
#include<iostream>
using namespace std;

class A {
	public:
		A(){cout<<"Constructor A"<<endl;}
		void foo(){cout<<"foo B"<<endl;}
};

class B {
	public:
		B(){cout<<"Constructor B"<<endl;}
		void foo(){cout<<"foo B"<<endl;}
};

class C : public A, public B{
	public:
		C(){cout<<"Constructor C"<<endl;}
};

int main(){
	C c;
	c.A::foo();
	c.B::foo();
}
*/

/*
	Il polimorfismo è il meccanismpoo per il quale oggetti di classi diverse rispondono in maniera
	diversa alla stessa invocazione.
	
	Il polimorfismo, si realizza attraverso le operazioni di overloading, che consistono fondamentalmente 
	nel definire più metodi con lo stesso nome ma dedicati a oggetti diversi;
	
	Binding --> Associazione tra chiamata a funzione e codice che la implementa
	Static Binding --> Associazione che avviene a tempo di compilazione
	Dynamic Binding --> Associazione che avviene a run-time
	
*/
/*
#include<iostream>
using namespace std;

class A {
	public:
		A(){cout<<"Constructor A"<<endl;}
		virtual void stampa(){cout<<"Stampa() di A"<<endl;}
		virtual void call(){private_fun();}
		
	private:
		void private_fun(){cout<<"Private_fun() di A"<<endl;}
};

class B : public A{
	public:
		B(){cout<<"Constructor B"<<endl;}
		void stampa() override{cout<<"Stampa() di B"<<endl;}
		void call(){A::call();}
};

int main(){
	A a;
	B b;
	
	a.stampa();
	b.stampa();
	
	A& ra = a;
	A& rb = b;  //perfettamente LEGALE
	
	ra.stampa();
	rb.stampa();
	
	A *pa = &a;
	A *pb = &b; //anche questo perfettamente LEGALE
	
	pa->stampa();
	pb->stampa();
	
	pb->call();
}
*/

/*
	Scrivere una classe template che prenda due tipi di dato generici e li utilizzi
	come tipi di dato per due attributi della classe stessa. Scrivere metodi set e get e un metodo 
	di stampa oltre al costruttore.
*/

/*
#include<iostream>
using namespace std;

template<class T, class C>
class A{
		T x;
		C y;
	
	public:
		A(T t, C c): x(t), y(c){cout<<"costruttore di A"<<endl;}
		void set_x(T x){
			this->x = x;
		}
		T get_x()const{
			return x;
		}
		void set_y(C y){
			this->y = y;
		}
		C get_y()const{
			return y;
		}
		void stampa(){
			cout<<"T x ="<<x<<", C y="<<y<<endl;
		}
};

int main(){
	A <double, string> a(10.8, "string");
	
	cout<<a.get_x()<<endl;
	cout<<a.get_y()<<endl;
	a.stampa();
	
	a.set_x(10.30);
	a.set_y("str");
	
	cout<<"Dopo i setter"<<endl;
	cout<<a.get_x()<<endl;
	cout<<a.get_y()<<endl;
	a.stampa();
	
}
*/

/*
	Enumeration --> coppie campi-valore, una sorta di variabili però non hanno bisogno di istanziazioni.
*/
#include<iostream>
using namespace std;

class Y{};

class A{
	
	int data;
	class B{};
	enum { a = 100};
	friend class X;
	friend Y;
	//friend class Y;
};

class X : A::B{
	A::B mx;
	class Y{
		A::B my;
	};
	int v[A::a];
};

int main(){
	
}