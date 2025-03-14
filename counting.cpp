/*Given an unsorted array of alphabets containing duplicate elements. Design an algorithm and implement it 
using a program to find which alphabet has maximum number of occurrences and print it. */

#include <iostream>
using namespace std;

void mostFrequentAlphabet(char arr[], int n) {
    int freq[26] = {0}; 

    for (int i = 0; i < n; i++) {
        freq[arr[i] - 'a']++;
    }

    int maxFreq = 0, maxIndex = -1;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxIndex = i;
        }
    }

    if (maxFreq == 1) {
        cout << "No Duplicates Present" << endl;
    } else {
        cout << char(maxIndex + 'a') << " - " << maxFreq << endl;
    }
}

int main() {
    int T;
    cout << "Enter the number of test cases: ";
    cin >> T;  

    while (T--) {
        int n;
        cout << "Enter array size: ";
        cin >> n;  

        char arr[n];
        cout << "Enter alphabets: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];  
        }

        mostFrequentAlphabet(arr, n);
    }

    return 0;
}