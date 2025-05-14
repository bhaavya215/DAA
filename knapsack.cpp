#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Item {
    int index;
    double weight, value, ratio;
};

// Comparator to sort items by value/weight ratio in descending order
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

int main() {
    int N;
    cout << "Enter the number of items: ";
    cin >> N;

    vector<double> weights(N), values(N);

    cout << "Enter the weights of the items: ";
    for (int i = 0; i < N; i++) {
        cin >> weights[i];
    }

    cout << "Enter the values of the items: ";
    for (int i = 0; i < N; i++) {
        cin >> values[i];
    }

    double W;
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    // Create and populate items
    vector<Item> items(N);
    for (int i = 0; i < N; i++) {
        items[i] = {i + 1, weights[i], values[i], values[i] / weights[i]};
    }

    // Sort by value-to-weight ratio
    sort(items.begin(), items.end(), compare);

    double totalValue = 0.0;
    vector<pair<int, double>> selectedItems; // item index and fraction

    for (const auto& item : items) {
        if (W == 0) break;

        if (item.weight <= W) {
            // Take whole item
            W -= item.weight;
            totalValue += item.value;
            selectedItems.push_back({item.index, 1.0});
        } else {
            // Take fractional part
            double fraction = W / item.weight;
            totalValue += item.value * fraction;
            selectedItems.push_back({item.index, fraction});
            W = 0;
        }
    }

    // Output
    cout << fixed << setprecision(2);
    cout << "\nMaximum value: " << totalValue << endl;
    cout << "Selected items (item number, fraction taken):" << endl;
    for (const auto& p : selectedItems) {
        cout << "Item " << p.first << ": " << p.second << endl;
    }

    return 0;
}