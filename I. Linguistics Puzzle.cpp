#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string getSymbolMapping(int n, const vector<string>& numbers) {
    string symbols(n, ' ');

    // Create a mapping of digits to symbols
    vector<int> digitMapping(n);
    for (int i = 0; i < n * n; ++i) {
        int num = 0;
        for (char c : numbers[i]) {
            num *= n;
            if (c >= 'a' && c <= 'z') {
                num += c - 'a';
            } else {
                num += c - 'A' + 26;
            }
        }
        digitMapping[i] = num;
    }

    // Sort the digit mapping in ascending order
    sort(digitMapping.begin(), digitMapping.end());

    // Assign symbols based on the sorted digit mapping
    for (int i = 0; i < n; ++i) {
        int digit = digitMapping[i];
        if (i < 26) {
            symbols[digit] = 'a' + i;
        } else {
            symbols[digit] = 'A' + (i - 26);
        }
    }

    return symbols;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        cin >> n;

        int numSymbols = n * n;
        vector<string> numbers(numSymbols);
        for (int i = 0; i < numSymbols; ++i) {
            cin >> numbers[i];
        }

        string symbolMapping = getSymbolMapping(n, numbers);
        cout << symbolMapping << endl;
    }

    return 0;
}
