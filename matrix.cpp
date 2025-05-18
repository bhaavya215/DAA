//WEEK 11, Q1
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main() {
    int n;
    cout << "Enter number of matrices to multiply: ";
    cin >> n;

    vector<int> p(n + 1);
    cout << "Enter the dimensions of each matrix as 'row col':" << endl;
    for (int i = 0; i < n; ++i) {
        int row, col;
        cout << "Matrix " << i + 1 << " (row col): ";
        cin >> row >> col;
        p[i] = row;
        if (i == n - 1) p[i + 1] = col; // last column goes to the end
    }

    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << "\nMinimum number of scalar multiplications needed: " << dp[0][n - 1] << endl;
    return 0;
}