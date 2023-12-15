#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

const int MOD = 998244353;

int countICPCishStrings(string s) {
    int n = s.length();

    vector<int> counts(3, 0);
    unordered_map<int, int> freqCount;

    for (char c : s) {
        if (c == 'C') counts[0]++;
        if (c == 'I') counts[1]++;
        if (c == 'P') counts[2]++;
    }

    for (int count : counts) {
        freqCount[count]++;
    }

    if (freqCount.size() < 2) {
        return 0;
    }

    int totalWays = 0;

    for (int i = 0; i < 3; i++) {
        int countToRemove = counts[i];
        counts[i] = 0;

        int remainingCount = n - countToRemove;

        // Check if remaining counts can form an ICPC-ish string
        if ((remainingCount % 2 == 0) && (remainingCount / 2 >= counts[0]) && (remainingCount / 2 >= counts[1]) &&
            (remainingCount / 2 <= counts[0] + counts[1])) {
            totalWays = (totalWays + freqCount[counts[2]]) % MOD;
        }

        counts[i] = countToRemove;
    }

    return totalWays;
}

int main() {
    string s;
    cin >> s;

    int ways = countICPCishStrings(s);

    cout << ways << endl;

    return 0;
}
