/*Given an unsorted array of integers, design an algorithm and implement it using a program to find whether 
two elements exist such that their sum is equal to the given key element. (Time Complexity = O(n log n)) */

#include <iostream>
#include <algorithm>
using namespace std;

void findPairWithSum(int a[], int n, int key) {
    sort(a, a + n); 

    int left = 0, right = n - 1;
    while (left < right) { 
        int sum = a[left] + a[right];
        if (sum == key) {
            cout << a[left] << " " << a[right] << endl;
            return;
        }
        else if (sum < key)
            left++;
        else
            right--; 
    }

    cout << "No Such Elements Exist" << endl;
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;  

    while (T--) {
        int n, key;
        cout << "Enter array size: ";
        cin >> n;  
        
        int a[n];
        cout << "Enter elements: ";
        for (int i = 0; i < n; i++) {
            cin >> a[i];  
        }

        cout << "Enter target sum: ";
        cin >> key;  
        findPairWithSum(a, n, key);
    }

    return 0;
}