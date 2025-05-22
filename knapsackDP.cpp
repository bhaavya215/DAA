//WEEK 12, Q2
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter number of items: ";
    cin >> n;

    vector<int> weights(n), values(n);
    cout << "Enter weights of items: ";
    for (int i = 0; i < n; i++)
        cin >> weights[i];

    cout << "Enter values of items: ";
    for (int i = 0; i < n; i++)
        cin >> values[i];

    int W;
    cout << "Enter knapsack capacity: ";
    cin >> W;

    // Create DP table
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    // Build DP table
    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (weights[i - 1] <= w)
                dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }

    // Output maximum value
    cout << "Maximum value = " << dp[n][W] << endl;

    // Trace back to find selected items
    cout << "Selected items:\n";
    int w = W;
    for (int i = n; i > 0 && w > 0; i--) {
        if (dp[i][w] != dp[i - 1][w]) {
            cout << "Item " << i << " (Weight: " << weights[i - 1] << ", Value: " << values[i - 1] << ")\n";
            w -= weights[i - 1];
        }
    }

    return 0;
}