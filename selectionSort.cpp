/*Given an unsorted array integers, design an algorithm & implement to sort this array using selection
sort. Program should also find the no. of comparisons & no. of swaps required. */

#include <iostream>
using namespace std;

void selectionSort(int a[], int n, int &comp, int &swap) {
    for(int i = 0; i < n - 1; i++) {
        int min = i;
        for(int j = i +1; j < n; j++) {
            comp++;
            if (a[min] > a[j]) {
                min = j;
            }
        }

        if (min != i) {
            swap++;
            int temp = a[i];
            a[i] = a [min];
            a[min] = temp;
        }
    }
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--) {
        int n;
        cout << "Enter size of the array: ";
        cin >> n;

        int a[n];
        cout << "Enter elements: ";
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int comp = 0;
        int swap = 0;
        
        selectionSort(a, n, comp, swap);

        cout << "Sorted Array: ";
        for(int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;

        cout << "Number of comparisons: " << comp << endl;
        cout << "Number of swaps: " << swap << endl;
    }

    return 0;
}