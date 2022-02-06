#include "mySort.h"

void mySort(int arr[], unsigned int first, unsigned int last) {
    int i, key, j, n;
    //n = last - first;
    int n2 = last - first; // doing this to accomodate the non-simple swap but is it correct? 
    myCopy(&n2, &n);

    //for (i = 1; i < n; i++) { 
    for(i = 1; myCompare(i, n) < 0; i++) {	
        //key = arr[i]; 
	myCopy(&arr[i], &key);
        //j = i - 1; 
	int j2 = i - 1;
	myCopy(&j2, &j);
        //while (j >= 0 && arr[j] > key) { 
        while (myCompare(j, 0) >= 0 && myCompare(arr[j], key) > 0) {
            //arr[j + 1] = arr[j]; // 
            myCopy(&arr[j], &arr[j + 1]);
            //j = j - 1; // j decrements
            int j3 = j - 1;
	    myCopy(&j3, &j);
        }
        //arr[j + 1] = key; 
        myCopy(&key, &arr[j + 1]);
    }
}

/*
void mySort(int arr[], unsigned int first, unsigned int last) {
//void insertionSort(int arr[], int n)
    int i, key, j, n;
    n = last - first;
    for (i = 1; i < n; i++) { // notice i starts from 1 instead of 0
        key = arr[i]; // Assigning a key to 1st unsorted element, elements to the right are "unsorted"
        j = i - 1; // j is being assigned 1 value below each i value, the "sorted" element

        Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position 
        while (j >= 0 && arr[j] > key) { // This slides everything greater to the right to "make room" for insertion
            arr[j + 1] = arr[j]; // 
            j = j - 1; // j decrements
        }
        arr[j + 1] = key; // this is the insertion
    }
}
*/ 
