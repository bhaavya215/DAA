//WEEK 11, Q3
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the set: ";
    cin >> n;

    vector<int> arr(n);
    int total = 0;
    cout << "Enter the elements of the set:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Element " << i + 1 << ": ";
        cin >> arr[i];
        total += arr[i];
    }

    if (total % 2 != 0) {
        cout << "\nPartition not possible: The total sum is odd." << endl;
        return 0;
    }

    int target = total / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(target + 1, false));
    for (int i = 0; i <= n; i++) dp[i][0] = true;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j < arr[i - 1])
                dp[i][j] = dp[i - 1][j];
            else
                dp[i][j] = dp[i - 1][j] || dp[i - 1][j - arr[i - 1]];
        }
    }

    cout << "\nCan the set be partitioned into two subsets with equal sum? ";
    cout << (dp[n][target] ? "YES" : "NO") << endl;
    return 0;
}