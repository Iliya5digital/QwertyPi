#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

vector<int> ZAlgorithm(const string& s) {
    int n = s.length();
    vector<int> z(n);
    int l = 0, r = 0;

    for (int i = 1; i < n; ++i) {
        if (i <= r)
            z[i] = min(r - i + 1, z[i - l]);

        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
            ++z[i];

        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }

    return z;
}

int main() {
    int n;
    cin >> n;

    string s;
    cin >> s;

    string t = s + s;
    reverse(s.begin(), s.end());
    t += s;

    vector<int> z = ZAlgorithm(t);

    // Count the frequencies of distinct palindromic substrings
    vector<long long> freq(n + 1);
    for (int i = n + 1; i < t.size(); ++i) {
        int len = z[i];
        if (len > n)
            continue;
        freq[len]++;
    }

    // Calculate the sum ∑f(t) * 2 * g(t)
    long long sum = 0;
    for (int len = n; len >= 1; --len) {
        if (freq[len] == 0)
            continue;
        sum = (sum + freq[len] * 2LL * len) % MOD;

        for (int i = len + len; i <= n; i += len) {
            freq[i] -= freq[len];
            if (freq[i] < 0)
                freq[i] += MOD;
        }
    }

    cout << sum << endl;

    return 0;
}
