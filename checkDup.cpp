//WEEK 13, Q2
#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

bool checkDup(const vector<int>& arr, int k) {
    unordered_set<int> window;

    for (int i = 0; i < arr.size(); i++) {
        if (window.find(arr[i]) != window.end()) {
            return true; // duplicate found
        }

        window.insert(arr[i]);

        if (window.size() > k) {
            window.erase(arr[i - k]);
        }
    }

    return false; // no duplicate found
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--) {
        int n;
        cout << "\nEnter size of array: ";
        cin >> n;

        vector<int> arr(n);
        cout << "Enter array elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cout << "Enter window size k: ";
        cin >> k;

        if (checkDup(arr, k)) {
            cout << "Duplicate present in window k" << endl;
        } else {
            cout << "Duplicate not present in window k" << endl;
        }
    }

    return 0;
}