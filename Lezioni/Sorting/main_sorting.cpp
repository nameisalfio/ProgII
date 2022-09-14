#include "sorting.h"

int main(){
	
	int array[10] = {8, 4, 10, 2, 7, 6, 5, 1, 9, 3};
	int n = sizeof(array)/sizeof(int);
	print(array, n);
	
	/*selection_sort(array, n);
	cout<<endl<<"Selection sort"<<endl;
	print(array, n);
	
	insertion_sort(array, n);
	cout<<endl<<"Insertion sort"<<endl;
	print(array, n);
	
	bubble_sort(array, n);
	cout<<endl<<"Bubble sort"<<endl;
	print(array, n);
	
	merge_sort(array, 0, n-1);
	cout<<endl<<"Merge sort"<<endl;
	print(array, n);*/

	quick_sort(array, n);
	cout<<endl<<"Quick sort"<<endl;
	print(array, n);
}