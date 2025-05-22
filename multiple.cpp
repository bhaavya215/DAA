//WEEK 13, Q3
#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Map to store product -> pair of indices
    unordered_map<int, pair<int, int>> productMap;

    // Try all unique pairs
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            int product = arr[i] * arr[j];

            // If this product was seen before
            if (productMap.find(product) != productMap.end()) {
                pair<int, int> prev = productMap[product];

                // Ensure all indices are distinct
                if (prev.first != i && prev.first != j && prev.second != i && prev.second != j) {
                    cout << "Pair (a, b): (" << arr[prev.first] << ", " << arr[prev.second] << ")\n";
                    cout << "Pair (c, d): (" << arr[i] << ", " << arr[j] << ")\n";
                    return 0;
                }
            } else {
                productMap[product] = {i, j};
            }
        }
    }

    cout << "No such pairs found.\n";
    return 0;
}