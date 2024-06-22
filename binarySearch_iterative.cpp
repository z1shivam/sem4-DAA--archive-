#include <stdio.h>
int binarySearch(int arr[], int l, int r, int x) {
    while (l <= r) {
        int m = l + (r - l) / 2;
        if (arr[m] == x)
            return m;
        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main(void) {
    int arr[100], x;
    printf("Enter the number of elements in the array (up to 100): ");
    scanf("%d", &x);
    if (x <= 0 || x > 100) {
        printf("Invalid number of elements.\n");
        return 1;
    }

    printf("Enter %d elements in sorted order:\n", x);
    for (int k = 0; k < x; k++) {
        scanf("%d", &arr[k]);
    }

    int a;
    printf("Enter the searching element: ");
    scanf("%d", &a);

    int result = binarySearch(arr, 0, x - 1, a);
    if (result == -1) {
        printf("Element is not present in array.\n");
    } else {
        printf("Element is present at index %d.\n", result);
    }

    return 0;
}
