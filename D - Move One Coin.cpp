#include <iostream>
#include <vector>

using namespace std;

struct Coin {
    int x, y;
};

vector<Coin> findMismatchedCoins(vector<vector<char>>& sourcePattern, vector<vector<char>>& targetPattern) {
    int h = sourcePattern.size();
    int w = sourcePattern[0].size();

    vector<Coin> sourceCoins;
    vector<Coin> targetCoins;

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            if (sourcePattern[i][j] == 'o') {
                sourceCoins.push_back({j, i});
            }
            if (targetPattern[i][j] == 'o') {
                targetCoins.push_back({j, i});
            }
        }
    }

    vector<Coin> mismatchedCoins;

    for (int i = 0; i < sourceCoins.size(); i++) {
        if (sourceCoins[i].x != targetCoins[i].x || sourceCoins[i].y != targetCoins[i].y) {
            mismatchedCoins.push_back(sourceCoins[i]);
        }
    }

    return mismatchedCoins;
}

int main() {
    int h, w;
    cin >> h >> w;

    vector<vector<char>> sourcePattern(h, vector<char>(w));

    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++) {
            cin >> sourcePattern[i][j];
        }
    }

    int H, W;
    cin >> H >> W;

    vector<vector<char>> targetPattern(H, vector<char>(W));

    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            cin >> targetPattern[i][j];
        }
    }

    vector<Coin> mismatchedCoins = findMismatchedCoins(sourcePattern, targetPattern);

    Coin sourceCoin = mismatchedCoins[0];
    int dx = targetPattern[0].size() / 2 - sourcePattern[0].size() / 2;
    int dy = targetPattern.size() / 2 - sourcePattern.size() / 2;
    Coin targetCoin = {sourceCoin.x + dx, sourceCoin.y + dy};

    cout << sourceCoin.x << " " << sourceCoin.y << endl;
    cout << targetCoin.x << " " << targetCoin.y << endl;

    return 0;
}
