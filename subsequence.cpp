//WEEK 12, Q1
#include <iostream>
#include <vector>
#include <string>
using namespace std;

string getLCS(const string &s1, const string &s2) {
    int m = s1.length(), n = s2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    // Build dp table
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = 1 + dp[i - 1][j - 1];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // Reconstruct LCS string
    string lcs = "";
    int i = m, j = n;
    while (i > 0 && j > 0) {
        if (s1[i - 1] == s2[j - 1]) {
            lcs = s1[i - 1] + lcs;
            i--; j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    return lcs;
}

int main() {
    string seq1, seq2;
    cout << "Enter first sequence: ";
    cin >> seq1;
    cout << "Enter second sequence: ";
    cin >> seq2;

    string lcs = getLCS(seq1, seq2);
    cout << "Longest Common Subsequence: " << lcs << endl;
    cout << "Length of LCS: " << lcs.length() << endl;

    return 0;
}