#include <stdio.h>
#include <stdlib.h>

/**
 *  The functions in this module implement a Heapdata structure
 *  of integers.
 */

static int heapSize = 0;
int heap[100];

/**
 * heapDelete() removes the biggest integer in the heap and returns it.
 *
 */

int heapDelete()
{
  return 0;  //A dummy return statement
}


/**
 * heapSize() returns the number of items in the Heap.
 *
 */
int heapSize2()
{
  return 0;  //A dummy return statement
}

void swap(int *x, int *y) {
	int temp;
	temp = *x;
	*x = *y;
	*y = temp;
} 

void maxHeapify(int arr[], int arrSize, int index) {
	int left = 2 * index + 1;
	int right = 2 * index + 2;
	int largest = index;

	
	if (left < heapSize && arr[left] > arr[largest])
		largest = left;
	//else 
		//largest = right;

	if (right < arrSize && arr[right] > arr[largest])
		largest = right;
		
    /*
	if (left < arrSize && arr[left] > arr[largest])
		largest = left;
	
	if (right < arrSize && arr[right] > arr[largest])
		largest = right;
		*/

	

	if (largest != index) {
		swap(&arr[index], &arr[largest]);
		maxHeapify(arr, arrSize, largest);
	}
}

void buildMaxHeap(int arr[], int arrSize) {
	heapSize = arrSize;
	int i;
	for (i = ((arrSize/2)-1); i >= 0; i--) 
		maxHeapify(arr, arrSize, i);
}

/**
 *  addHeap(thing2add) adds the "thing2add" to the Heap.
 *
 */
void addHeap(int thing2add)
{
	//heapSize++;
	heap[heapSize] = thing2add;
	heapSize++;

	//int currentSize = sizeof(heap) / sizeof(heap[0]);
	buildMaxHeap(heap, heapSize);

	//int temp = heapSize;
	//int parent = 
	//while(
	//buildMaxHeap(heap, heapSize + 1);:
	//buildMaxHeap(heap, 100);
	// For test
	//int i = 0;
	//for (i = 0; i < heapSize; i++)
	//	fprintf(stdout, "%d ", heap[i]);
}

// for testing purposes
void printHeap() {
	int i;
	for (i = 0; i < heapSize; i++)
		fprintf(stdout, "%d ", heap[i]);
}