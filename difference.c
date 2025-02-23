/*Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.*/
#include <stdio.h>

int countPairs(int a[], int n, int k) {
    int count = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[j] - a[i] == k || a[i] - a[j] == k) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    int n, k;

    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter %d non-negative integers: \n", n);
    for (int i = 0; i < n; i++) {
        printf("Element %d: ", i+1);
        scanf("%d", &a[i]);
    }

    printf("Enter the difference value (K): ");
    scanf("%d", &k);

    int result = countPairs(a, n, k);
    printf("Number of pairs with difference %d: %d\n", k, result);

    return 0;
}