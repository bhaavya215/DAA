//WEEK 12, Q3
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;

    // Sort the string to get lexicographic starting point
    sort(str.begin(), str.end());

    cout << "Permutations in lexicographic order:\n";
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));

    return 0;
}