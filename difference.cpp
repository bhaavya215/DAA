/*Given an array of nonnegative integers, design an algorithm and a program to count the number
of pairs of integers such that their difference is equal to a given key, K.*/
#include <iostream>
#include <algorithm>
using namespace std;

int count(int a[], int n, int k) {
    int c = 0;
    int i = 0, j = 1;
    
    while(j < n) {
        if(a[j] - a[i] == k) {
            c++;
            i++;
            j++;
        }
        else if(a[j] - a[i] < k) {
            j++;
        }
        else {
            i++;
        }
    }
    return c;
}

int main() {
    int a[] = {3, 4, 1, 5, 2};
    int n = sizeof(a)/sizeof(a[0]);

    sort(a, a + n);

    int k;
    cout << "Enter key value: ";
    cin >> k;

    int result = count(a, n, k);
    cout << "Number of pairs with difference " << k << ": " << result << endl;

    return 0;
}