// LINEAR SEARCH
#include <stdio.h>

int linearSearch(int a[], int size, int key) {
    for (int i = 0; i < size; i++) {
        if (a[i] == key)
            return i; // Return index if found
    }
    return -1; // Return -1 if not found
}

int main() {
    int a[] = {10, 25, 30, 45, 50};
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int size = sizeof(a) / sizeof(a[0]);
    int result = linearSearch(a, size, key);

    if (result != -1)
        printf("Element found at index %d.\n", result);
    else
        printf("Element NOT found.\n");

    return 0;
}