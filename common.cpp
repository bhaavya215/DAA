/*You have been given two sorted integer arrays of size m and n. Design an algorithm and implement it using 
a program to find list of elements which are common to both. (Time Complexity = O(m+n))*/

#include <iostream>
using namespace std;

void findCommonElements(int arr1[], int m, int arr2[], int n) {
    int i = 0, j = 0;
    bool found = false;

    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {  
            cout << arr1[i] << " ";
            found = true;
            i++;
            j++;
        } 
        else if (arr1[i] < arr2[j]) {
            i++;  
        } 
        else {
            j++; 
        }
    }

    if (!found) {
        cout << "No Common Elements";
    }
    cout << endl;
}

int main() {
    int m, n;
    cout << "Enter size of 1st array: ";
    cin >> m;  // Size of first array

    int arr1[m];
    cout << "Enter elements in 1st array: ";
    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    cout << "Enter size of 2nd array: ";
    cin >> n;  // Size of second array

    int arr2[n];
    cout << "Enter elements in 2nd array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    findCommonElements(arr1, m, arr2, n);

    return 0;
}