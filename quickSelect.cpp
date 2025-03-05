/*Given an unsorted array of integers, design an algorithm & implement it using a program to find Kth smallest
or largest element in the array. (worst case time complexity = O(n))*/

#include <iostream>
//#include <cstdlib>
using namespace std;

int partition(int a[], int left, int right) {
    int pivot = a[right];
    int i = left - 1;

    for(int j = left; j < right; j++) {
        if(a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[right]);
    return (i + 1);
}

int quickSelect(int a[], int left, int right, int k) {
    if(left <= right) {
        int pivotIndex = partition(a, left, right);

        if(pivotIndex == k)
            return a[pivotIndex];
        else if(pivotIndex > k)
            return quickSelect(a, left, pivotIndex - 1, k);
        else 
            return quickSelect(a, pivotIndex + 1, right, k);
    }
    return -1;
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    while (T--) {
        int n;
        cout << "Enter array size: ";
        cin >> n;

        int a[n];
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int k;
        cout << "Enter value of K: ";
        cin >> k;

        cout << "The " << k << "th smallest element is: " << quickSelect(a, 0, n - 1, k - 1) << endl;
    }
    return 0;
}