/*Given an unsorted array of integers, design an algorithm & implement it using a program to sort an array of
elements by dividing the array into two subarrays & combining these subarrays after sorting each one of them.
Your program should also find no. of comparisons & inversions during sorting the array.*/

#include <iostream>
using namespace std;

void merge(int a[], int left, int mid, int right, int &comp, int &inv) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        comp++;
        if (L[i] <= R[j]) {
            a[k++] = L[i++];
        }
        else {
            a[k++] = R[j++];
            inv +=  (n1 - i);
        }
            
    }

    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(int a[], int left, int right, int &comp, int &inv) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid, comp, inv);
        mergeSort(a, mid + 1, right, comp, inv);
        merge(a, left, mid, right, comp, inv);
    }
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    while (T--) {
        int n;
        cout << "Enter size: ";
        cin >> n;

        int a[n];
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        int comp = 0, inv = 0;
        mergeSort(a, 0, n - 1, comp, inv);

        cout << "Sorted array: ";
        for (int i = 0; i < n; i++) {
            cout << a[i] << " ";
        }
        cout << endl;

        cout << "Number of comparisons: " << comp << endl;
        cout << "Number of inversions: " << inv << endl;
    }

    return 0;
}