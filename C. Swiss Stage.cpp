#include <iostream>
using namespace std;

int main() {
    int x, y;
    cin >> x >> y;

    int additionalGames = 0;

    if (x == 3 || y == 3) {
        // Team HCG has already accumulated three wins or three losses,
        // so no additional games are needed to advance to the next stage
        cout << additionalGames << endl;
        return 0;
    }

    int totalGames = x + y;

    if ((totalGames % 2 == 0) && ((x + y) >= 5)) {
        // Each round involves two teams, and to reach the next stage,
        // Team HCG needs to play at least 5 games in total.
        // If the total number of games played by Team HCG is even,
        // and the total games played is at least 5,
        // Team HCG needs to play additional 3 games to advance.
        additionalGames = 3;
    }
    else if ((totalGames % 2 == 1) && ((x + y) >= 3)) {
        // If the total number of games played by Team HCG is odd,
        // and the total games played is at least 3,
        // Team HCG needs to play additional 2 games to advance.
        additionalGames = 2;
    }
    else {
        // In all other cases, no additional games are needed to advance.
        additionalGames = 0;
    }

    cout << additionalGames << endl;
    return 0;
}
