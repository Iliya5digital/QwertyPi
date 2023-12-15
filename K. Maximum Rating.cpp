#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000000007;

// Function to calculate the number of set bits in a number
int countSetBits(int n) {
    int count = 0;
    while (n > 0) {
        count += n & 1;
        n >>= 1;
    }
    return count;
}

// Function to calculate the number of edges to cut
int calculateEdgesToCut(int s, int t, int k) {
    int minSetBits = max(countSetBits(s), countSetBits(t));
    int diffSetBits = countSetBits(s ^ t);

    // Check if it's impossible to reach vertex t for the k-th time
    if ((s == t && k > 1) || (diffSetBits > k) || ((k - diffSetBits) % 2 != 0))
        return -1;

    int maxEdges = 0;
    for (int bit = 0; bit < 64; bit++) {
        if ((s >> bit) & 1) {
            int weight = bit + 1;
            if (weight <= k && ((t >> bit) & 1))
                maxEdges = max(maxEdges, weight);
        }
    }

    int edgesToCut = (k - diffSetBits) / 2 + maxEdges;
    return edgesToCut;
}

int main() {
    int T;
    cin >> T;
    
    while (T--) {
        int s, t, k;
        cin >> s >> t >> k;

        int result = calculateEdgesToCut(s, t, k);
        cout << result << endl;
    }

    return 0;
}
