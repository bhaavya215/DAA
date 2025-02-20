/*Given a sorted array of positive integers containing few duplicate elements, design an algorithm & 
implement it using a program to find whether the given key element is present in the array or not. 
If present, then also find the number of copies of given key.*/
#include<stdio.h>

int firstOccurance(int a[], int n, int key) {
    int low = 0, high = n - 1, first = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) {
            first = mid;
            high = mid - 1;
        }
        else if (a[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return first;
}

int lastOccurance(int a[], int n, int key) {
    int low = 0, high = n - 1, last = -1;
    while(low <= high) {
        int mid = low + (high - low) / 2;
        if (a[mid] == key) {
            last = mid;
            low = mid + 1;
        }
        else if (a[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    return last;
}

int main() {
    int a[] = {2, 3, 3, 4, 5, 5, 5 ,5, 5, 7, 8, 8, 8, 9};
    int n = sizeof(a) / sizeof(a[0]);

    int key;
    printf("Enter the key value: ");
    scanf("%d", &key);

    int first = firstOccurance(a, n, key);
    int last = lastOccurance(a, n, key);

    if(first != -1) {
        printf("Key found in the array.\n");
        printf("Number of copies of key %d: %d\n", key, (last - first + 1));
    }
    else {
        printf("Key NOT found in the array.\n");
    }

    return 0;
}