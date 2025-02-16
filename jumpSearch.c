// JUMP SEARCH
#include <stdio.h>
#include <math.h>

int jumpSearch(int a[], int size, int key) {
    int jump = sqrt(size); 
    int prev = 0;

    // Find the block where key may be present
    while (jump < size && a[jump] <= key) {  
        prev = jump;
        jump += sqrt(size);
        if (jump > size - 1)  
            jump = size;
    }

    // Perform linear search in the found block
    for (int i = prev; i < jump; i++) {
        if (a[i] == key)
            return i; // Return index if found
    }

    return -1; // Key not found
}

int main() {
    int a[] = {1, 4, 6, 8, 11, 19, 21, 54, 72, 83, 99};
    int key;

    printf("Enter the element to search: ");
    scanf("%d", &key);

    int size = sizeof(a) / sizeof(a[0]);
    int result = jumpSearch(a, size, key);

    if (result != -1)
        printf("Element found at index %d.\n", result);
    else
        printf("Element NOT found.\n");

    return 0;
}
