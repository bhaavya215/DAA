/*Given a sorted array of positive integers, design an algorithm & implement it using a program to find
3 indices, i, j, k such that a[i] + a[j] = a[k].*/
#include <stdio.h>

void findIndex(int a[], int n) {
    for (int k = 2; k < n; k++) { 
        int i = 0, j = k - 1;
        while (i < j) {
            int sum = a[i] + a[j];
            if (sum == a[k]) {
                printf("Indices found: i = %d, j = %d, k = %d\n", i, j, k);
                printf("Sum: %d + %d = %d\n", a[i], a[j], a[k]);
                return; 
            } else if (sum < a[k]) {
                i++;
            } else {
                j--; 
            }
        }
    }
    printf("No such indices found.\n");
}

int main() {
    int a[] = {3, 7, 9, 11, 12, 25}; 
    int n = sizeof(a) / sizeof(a[0]);

    findIndex(a, n);
    return 0;
}