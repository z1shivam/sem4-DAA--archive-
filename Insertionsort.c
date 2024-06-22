
#include <math.h>
#include <stdio.h>


void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++) {
		key = arr[i];
		j = i - 1;

		
		
		while (j >= 0 && arr[j] > key) {
			arr[j + 1] = arr[j];
			j = j - 1;
		}
		arr[j + 1] = key;
	}
}


void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
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

	insertionSort(arr, x);
	printArray(arr, x);

	return 0;
}

