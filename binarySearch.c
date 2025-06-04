// BINARY SEARCH
#include <stdio.h>

int binarySearch(int a[], int size, int key) {
    int low = 0, high = size - 1, mid;

    while (low <= high) {
        mid = low + (high - low) / 2;
        if (a[mid] == key)
            return mid; // Key found, return index
        else if (a[mid] < key)
            low = mid + 1; // Search in right half
        else
            high = mid - 1; // Search in left half
    }
    return -1; // Key not found
}

int main() {
    int a[] = {11, 22, 33, 44, 55, 67, 89, 93, 101, 121};
    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);

    int size = sizeof(a) / sizeof(a[0]);
    int result = binarySearch(a, size, key);

    if (result != -1)
        printf("Element found at index %d.\n", result);
    else
        printf("Element NOT found.\n");

    return 0;
}