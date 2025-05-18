//WEEK 11, Q2
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int m, n;
    cout << "Enter the number of different coin types: ";
    cin >> m;

    vector<int> coins(m);
    cout << "Enter the value of each coin type:" << endl;
    for (int i = 0; i < m; i++) {
        cout << "Coin " << i + 1 << ": ";
        cin >> coins[i];
    }

    cout << "Enter the total amount to form: ";
    cin >> n;

    vector<int> dp(n + 1, 0);
    dp[0] = 1;

    for (int coin : coins) {
        for (int i = coin; i <= n; i++) {
            dp[i] += dp[i - coin];
        }
    }

    cout << "\nNumber of ways to make the amount " << n << ": " << dp[n] << endl;
    return 0;
}