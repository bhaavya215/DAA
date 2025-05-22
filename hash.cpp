//WEEK 13, Q1
#include <iostream>
#include <unordered_map>
#include <set>
using namespace std;

int main() {
    int n;
    cout << "Enter the size of the character array: ";
    cin >> n;

    char ch;
    unordered_map<char, int> freqMap;

    cout << "Enter " << n << " characters:\n";
    for (int i = 0; i < n; i++) {
        cin >> ch;
        freqMap[ch]++;
    }

    // Use a set to sort characters alphabetically
    set<char> sortedKeys;
    for (auto &entry : freqMap)
        sortedKeys.insert(entry.first);

    cout << "Character frequencies (in alphabetical order):\n";
    for (char c : sortedKeys)
        cout << c << ": " << freqMap[c] << endl;

    return 0;
}