/*Given an unsorted array of integers, design an algorithm and a program to sort the array using 
insertion sort. Your program should be able to find number of comparisons and shifts required for 
sorting the array.*/
#include <iostream>
using namespace std;

void insertionSort(int a[], int n, int &comp, int &sh) {
    for(int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;

        while(j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
            comp++;
            sh++;
        }

        a[j + 1] = temp;
        if (j >= 0) {
            comp++;
        }
    }
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while(T--) {
        int n;
        cout << "Enter size of array: ";
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int comp = 0;
        int sh = 0;

        insertionSort(a, n, comp, sh);

        cout << "Sorted Array: ";
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;

        cout << "Total no. of comparisons: " << comp << endl;
        cout << "Total no. of shifts: " << sh << endl;
    }

    return 0;
}