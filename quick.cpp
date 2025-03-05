/*Given an unsorted array of integers, design an algorithm & implement it using a program to sort an arrray
of elements by partitioning the array into 2 subarrays based on a pivot element such that one of the subarrays
based on pivot element such that one of the subarray holds values smaller than the pivot while another subarray
holds values greater than the pivot element. Pivot element should be selected randomly from the array. Your
program should also find no. of comparisons & swaps required for sorting the array.*/

#include <iostream>
#include <cstdlib>
using namespace std;

void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

int partition(int a[], int low, int high, int &comps, int &swaps) {
    int pivotIndex = low + rand() % (high - low + 1);
    swap(a[pivotIndex], a[high]);

    int pivot = a[high];
    int i = low - 1;

    for(int j = low; j < high; j++) {
        comps++;
        if(a[j] <= pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[high]);
    swaps++;
    return (i + 1);
}

void quickSort(int a[], int low, int high, int &comps, int &swaps) {
    if (low < high) {
        int pivotIndex = partition(a, low, high, comps, swaps);
        quickSort(a, low, pivotIndex - 1, comps, swaps);
        quickSort(a, pivotIndex + 1, high, comps, swaps);
    }
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

        int comps = 0, swaps = 0;
        quickSort(a, 0, n - 1, comps, swaps);

        cout << "Sorted array: ";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;

        cout << "Number of comparisons: " << comps << endl;
        cout << "Number of swaps: " << swaps << endl;
    }

    return 0;
}