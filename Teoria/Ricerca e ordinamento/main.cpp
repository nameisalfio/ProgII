#include <iostream>
#include <math.h>
using namespace std;

#include "sorting.h"

int main(){

    int array[10] = {1, 4, 6, 7, 2, 8, 3, 9, 0, 5}; //Necessaria ricerca sequenziale
    //int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; //Possibile usare ricerca binaria
    int n = sizeof(array)/sizeof(int);

    print(array, n);

    //selection_sort(array, n);
    //insertion_sort(array, n);
    //bubble_sort(array, n);
    //merge_sort(array, n);
    quick_sort(array, n);

    print(array, n);

}