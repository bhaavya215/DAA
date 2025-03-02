/*Given an unsorted array of positive integers, design an algorithm & implement it using a program to find
whether there are any duplicate elements in the array or not. (use sorting) (time complexity: O(nlogn)) */

#include <iostream>
using namespace std;

void merge(int a[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = a[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }

    while (i < n1)
        a[k++] = L[i++];
    while (j < n2)
        a[k++] = R[j++];
}

void mergeSort(int a[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(a, left, mid);
        mergeSort(a, mid + 1, right);
        merge(a, left, mid, right);
    }
}


bool duplicate(int a[], int n) {
    for(int i = 0; i < n - 1; i++) {
        if(a[i] == a[i + 1]) {
            return true;
        }
    }
    return false;
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;

    while(T--) {
        int n;
        cout << "Enter size: ";
        cin >> n;

        int a[n];
        cout << "Enter elements: ";
        for(int i = 0; i < n; i++) {
            cin >> a[i];
        }

        mergeSort(a, 0, n - 1);

        if(duplicate(a, n)) {
            cout << "The array contains duplicates." << endl;
        } else {
            cout << "The array does NOT contain any duplicates." << endl;
        }
    }

    return 0;
}