// RECURSIVE BINARY SEARCH
#include <stdio.h>

int binarySearch(int a[], int low, int high, int key) {
    if (low > high)
        return -1; // Base case: Element not found

    int mid = (low + high) / 2;

    if (a[mid] == key)
        return mid; // Found the key, return index
    if (a[mid] < key)
        return binarySearch(a, mid + 1, high, key); // Search right side
    return binarySearch(a, low, mid - 1, key); // Search left side
}

int main() {
    int a[] = {11, 22, 33, 44, 55, 67, 89, 93, 101, 121};
    int key;

    printf("Enter element to search: ");
    scanf("%d", &key);

    int size = sizeof(a) / sizeof(a[0]);
    int result = binarySearch(a, 0, size - 1, key);

    if (result != -1)
        printf("Element found at index %d.\n", result);
    else
        printf("Element NOT found.\n");

    return 0;
}
