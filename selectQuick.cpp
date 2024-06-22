#include <iostream>

void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Partition function for Select2
int partition(int arr[], int low, int high) {
  int pivot = arr[high]; // pivot element
  int i = (low - 1);        // index of smaller element

  for (int j = low; j <= high - 1; j++) {
    // Check if current element is smaller than the pivot
    if (arr[j] < pivot) {
      i++;    // increment index of smaller element
      swap(&arr[i], &arr[j]);
    }
  }
  swap(&arr[i + 1], &arr[high]); // swap the pivot element with the element at i+1
  return (i + 1);
}

int Select2(int arr[], int k, int low, int up) {
  // Number of elements
  int n = up - low + 1;

  // Base cases
  if (n <= 1) {
    return low;
  }

  // If n is small, use insertion sort
  if (n <= 5) {
    for (int i = low + 1; i <= up; i++) {
      int key = arr[i];
      int j = i - 1;

      while (j >= low && arr[j] > key) {
        arr[j + 1] = arr[j];
        j--;
      }
      arr[j + 1] = key;
    }
    return low + k - 1;
  }

  // Partition the array around a random pivot
  int pivot_index = low + rand() % (up - low + 1);
  swap(&arr[pivot_index], &arr[up]);
  int pi = partition(arr, low, up);

  // If k'th smallest is at its position
  if (pi - low + 1 == k) {
    return pi;
  } else if (k < pi - low + 1) {
    return Select2(arr, k, low, pi - 1);
  } else {
    return Select2(arr, k - (pi - low + 1), pi + 1, up);
  }
}

// Print array elements
void printArray(int arr[], int n) {
  for (int i = 0; i < n; ++i) {
    std::cout << arr[i] << " ";
  }
  std::cout << "\n";
}

int main() {
  int arr[] = {10, 7, 8, 9, 1, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  int k = 3; // Find the 3rd smallest element

  int kthSmallest = Select2(arr, k, 0, n - 1);

  std::cout << "kth smallest element: " << arr[kthSmallest] << "\n";

  return 0;
}
