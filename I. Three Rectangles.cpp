#include <iostream>
using namespace std;

const int MOD = 1000000007;

// Function to calculate the modular exponentiation
int powMod(int base, int power) {
    int result = 1;
    while (power > 0) {
        if (power & 1)
            result = (1LL * result * base) % MOD;
        base = (1LL * base * base) % MOD;
        power >>= 1;
    }
    return result;
}

// Function to calculate the factorial modulo MOD
int factorialMod(int n) {
    int result = 1;
    for (int i = 2; i <= n; i++)
        result = (1LL * result * i) % MOD;
    return result;
}

// Function to calculate the modular inverse of a number
int modInverse(int n) {
    return powMod(n, MOD - 2);
}

// Function to calculate the number of placements
int calculatePlacements(int H, int W, int h1, int w1, int h2, int w2, int h3, int w3) {
    int totalPlacements = 0;

    // Calculate the number of possible placements for each card individually
    int placements1 = ((H - h1 + 1) * (W - w1 + 1)) % MOD;
    int placements2 = ((H - h2 + 1) * (W - w2 + 1)) % MOD;
    int placements3 = ((H - h3 + 1) * (W - w3 + 1)) % MOD;

    // Calculate the total number of placements by multiplying the number of placements for each card
    totalPlacements = ((1LL * placements1 * placements2) % MOD * placements3) % MOD;

    // Calculate the overcounted placements and subtract them
    int overlaps1 = ((H - h1 - h2 + 2) * (W - w1 - w2 + 2)) % MOD;
    int overlaps2 = ((H - h2 - h3 + 2) * (W - w2 - w3 + 2)) % MOD;
    int overlaps3 = ((H - h1 - h3 + 2) * (W - w1 - w3 + 2)) % MOD;
    int overlaps12 = ((H - h1 - h2 - h3 + 3) * (W - w1 - w2 - w3 + 3)) % MOD;

    totalPlacements = (totalPlacements - overlaps1 + MOD) % MOD;
    totalPlacements = (totalPlacements - overlaps2 + MOD) % MOD;
    totalPlacements = (totalPlacements - overlaps3 + MOD) % MOD;
    totalPlacements = (totalPlacements + overlaps12) % MOD;

    // Divide the placements by the factorial of the number of cards to remove permutations
    totalPlacements = (1LL * totalPlacements * modInverse(factorialMod(3))) % MOD;

    return totalPlacements;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        int H, W;
        cin >> H >> W;

        int h1, w1, h2, w2, h3, w3;
        cin >> h1 >> w1 >> h2 >> w2 >> h3 >> w3;

        int result = calculatePlacements(H, W, h1, w1, h2, w2, h3, w3);
        cout << result << endl;
    }

    return 0;
}
