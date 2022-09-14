#include<iostream>
using namespace std;

template<typename T>
class Static_stack{
	
		T* array;
		int top = -1; //Indice della cima
		int size = 0;
		int maxSize = -1;
	
	public:
		
		Static_stack(int maxSize):maxSize(maxSize){
			array = new T[maxSize];
		}
		
		bool isEmpty(){
			
			return top == -1;
		}
		
		T get_top()const{
			
			if(isEmpty())
				return -1;
			
			return array[top];
		}
		
		void push(T val){

			if(top == maxSize-1)
			{
				cerr << "Full stack" << endl;
				return;
			}

			size++;
			array[++top] = val; //Prima aggiorno l'indice e poi inserisco val
		}
		
		T pop(){
			
			if(isEmpty())
				return -1;
			
			size--;
			return array[top--]; //Prima restituisco e poi decremento
		}
		
		friend ostream& operator<< (ostream& os, Static_stack& s){
			
			if(s.isEmpty())
			{
				os << "\nEmpty Stack" << endl;
				return os;
			}

			os << "\nSize = " << s.size << endl;
			os << "\nStatic_stack : maxSize= " << s.maxSize << endl;
			//os << "-------------------------------------------------" << endl;
			for(int i=s.top; i>=0; i--)
				os << s.array[i] << " ";
			
			os << endl;
			return os;
		}
};

int main(){
	
	Static_stack<int> st(5);
	
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);
	
	cout << st << endl;
}