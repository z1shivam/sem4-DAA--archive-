#include <stdbool.h>
#include <stdio.h>
void swap(int* xp, int* yp)
{
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

void bubbleSort(int arr[], int n)
{
	int i, j;
	bool swapped;
	for (i = 0; i < n - 1; i++) {
		swapped = false;
		for (j = 0; j < n - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
				swapped = true;
			}
		}
		
		if (swapped == false)
			break;
	}
}

void printArray(int arr[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		printf("%d ", arr[i]);
}


int main()
{
	int arr[100],x;
	printf("Enter the no of element in array:");
	scanf("%d",&x);
	int k;
	for (k=0;k<x;k++)
	{
		scanf("%d",&arr[k]);
	}
	bubbleSort(arr, x);
	printf("Sorted array: \n");
	printArray(arr, x);
	return 0;
}

