#include <stdio.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

void swap( int *a, int *b){
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void heapify(int arr[], int n, int i){
	//int root = arr[i];
	int largest = i;
	int leftChild = (2*i) + 1;
	int rightChild = (2*i) + 2;
	int temp;

	if(leftChild < n && arr[leftChild]>arr[largest]){
		largest = leftChild;
	}

	if(rightChild < n && arr[rightChild]>arr[largest]){
		largest = rightChild;
	}

	if(largest!=i){
		// temp = arr[i];
		// arr[i] = arr[largest];
		// arr[largest] = temp;
		swap(&arr[i],&arr[largest]);
		heapify(arr,n,largest);
	}
}

void heapSort(int arr[], int n) {

	printf("TEST\n");
	int temp;
	for (int i = (n/2)-1; i >= 0; i--)
	{	
		heapify(arr,n,i);
	}

	for (int i = n-1; i >=0; i--)
	{
		// temp = arr[0];
		// arr[0] = arr[1];
		// arr[1] = temp;
		swap(&arr[0],&arr[i]);
		heapify(arr,i,0);
	}
}

void printArray(int arr[], int n){
	for (int i = 0; i < n; ++i)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
}

void genArray(int arr[], int n){
	srand(time(NULL));

	for (int i = 0; i < n; ++i)
	{
		/* code */
		arr[i]  =rand()%n;
	}
}

int main(int argc, char* argv[])
{

	if(argc!=2){
		printf("usage: ./a.out <LENGTH>");
		exit(1);
	}
    int arr[100];
    //int n = sizeof(arr)/sizeof(arr[0]);
 	
    printf("Here's the array as it is.\n");
    genArray(arr,atoi(argv[1]));
 	printArray(arr,atoi(argv[1]));
    heapSort(arr, atoi(argv[1]));
 
    printf("Here's the array sorted via heap sort:\n");
    printArray(arr, atoi(argv[1]));
}