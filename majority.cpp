//WEEK 10, Q3
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to find majority element using Boyer-Moore Voting Algorithm
int findMajorityCandidate(const vector<int>& arr) {
    int candidate = -1, count = 0;
    for (int num : arr) {
        if (count == 0) {
            candidate = num;
            count = 1;
        } else if (num == candidate) {
            count++;
        } else {
            count--;
        }
    }
    return candidate;
}

bool isMajority(const vector<int>& arr, int candidate) {
    int count = 0;
    for (int num : arr) {
        if (num == candidate) count++;
    }
    return count > arr.size() / 2;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter elements: " << endl;
    for (int& x : arr) cin >> x;

    // Find majority element
    int candidate = findMajorityCandidate(arr);
    if (isMajority(arr, candidate)) {
        cout << "Majority element exists: YES (Element = " << candidate << ")" << endl;
    } else {
        cout << "Majority element exists: NO" << endl;
    }

    // Find median
    sort(arr.begin(), arr.end());
    int median;
    if (n % 2 == 1) {
        median = arr[n / 2];
    } else {
        median = (arr[n / 2 - 1] + arr[n / 2]) / 2; // integer median
    }

    cout << "Median of the array is: " << median << endl;

    return 0;
}