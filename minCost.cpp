#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// Function to calculate minimum merge cost
int minMergeCost(vector<int>& files) {
    priority_queue<int, vector<int>, greater<int>> minHeap(files.begin(), files.end());
    int totalCost = 0;

    while (minHeap.size() > 1) {
        int first = minHeap.top(); minHeap.pop();
        int second = minHeap.top(); minHeap.pop();

        int merged = first + second;
        totalCost += merged;
        minHeap.push(merged);
    }

    return totalCost;
}

int main() {
    int n;
    cout << "Enter the number of files: ";
    cin >> n;

    vector<int> files(n);
    cout << "Enter the sizes of the files:\n";
    for (int i = 0; i < n; i++) {
        cout << "File " << i + 1 << ": ";
        cin >> files[i];
    }

    int result = minMergeCost(files);
    cout << "Minimum computation cost to merge all files: " << result << endl;

    return 0;
}