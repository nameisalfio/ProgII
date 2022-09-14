#include <iostream>
using namespace std;

template <typename T>
class MyArray{
	
	private:
		T* vet;
		int len;
	
	public:
		
		MyArray(int len){
			this->len = len;
			vet = new T[len]; 
		}
		void print(){
			cout<<"\nPrint: "<<endl;
			for(int i=0; i<len; i++)
				cout<<vet[i]<<" ";
		}
		T at(int i)const{
			return vet[i];
		}
		void at(int i, T x){
			vet[i] = x;
		}
		int size()const{
			return len;
		}
		T* getpointer(){
			return &vet[0]; //vet
		}
		void copy(MyArray<T> *dst){
			for(int i=0; i<len; i++)
				dst->at(i, this->vet[i]);  //setter
		}
};

int main(){
	
	MyArray<int> ma(4);
	MyArray<int> ma2 = ma;
	ma.copy(&ma2);
	ma.print();
	ma2.print();
}