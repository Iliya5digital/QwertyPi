#include <iostream>
using namespace std;

int main() {
    int x, y, p, q;
    cin >> x >> y >> p >> q;

    int trips = 0;

    while (x > 0) {
        if (p >= x && q >= y) {
            // If there are enough available spots on the boat and the wolves won't eat the sheep,
            // we can transport all the sheep in one trip and be safe
            trips++;
            break;
        }

        // Calculate the number of trips required based on the maximum capacity of the boat and the number of available animals
        int sheepOnBoat = min(p, x);
        int wolvesOnBoat = p - sheepOnBoat;

        // Check if the wolves would eat the sheep on this side of the river
        if (wolvesOnBoat > sheepOnBoat + q) {
            // It's impossible to transport the sheep safely
            cout << -1 << endl;
            return 0;
        }

        // Update the remaining number of sheep and wolves
        x -= sheepOnBoat;
        y -= wolvesOnBoat;

        // Increment the number of trips
        trips++;
    }

    cout << trips << endl;
    return 0;
}
