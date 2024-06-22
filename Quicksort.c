#include <stdio.h>


void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int partition(int arr[], int low, int high)
{

	int pivot = arr[high];


	
	int i = (low - 1);
	int j;

	for (j = low; j <= high - 1; j++) {

	
		if (arr[j] < pivot) {

			
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}



void quickSort(int arr[], int low, int high)
{
	if (low < high) {

		
		
		int pi = partition(arr, low, high);

		
		
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
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

	
	quickSort(arr, 0, x - 1);
	printf("Sorted array: \n");
	int i;
	for ( i = 0; i < x; i++)
		printf("%d ", arr[i]);
	return 0;
}

