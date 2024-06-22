#include <iostream>
#include <climits>

using namespace std;

// Function to find the minimum and maximum elements iteratively
void findMinMax(int arr[], int n, int &min, int &max) {
    // Initialize min and max with the first element of the array
    min = INT_MAX;
    max = INT_MIN;

    // Traverse through the array and update min and max
    for (int i = 0; i < n; i++) {
        if (arr[i] < min)
            min = arr[i];
        if (arr[i] > max)
            max = arr[i];
    }
}

int main() {
    int arr[] = {3, 15, 91, 102, 2, 81, 7, 6, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    int min, max;
    findMinMax(arr, n, min, max);

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    return 0;
}

