#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    vector<pair<int, int>> houses; // pair of (startDay, endDay)
    vector<int> visitDates(n); // stores the visit date for each house

    for (int i = 0; i < n; i++) {
        int startDay, endDay;
        cin >> startDay >> endDay;
        houses.push_back({startDay, endDay});
    }

    int currDate = 1; // initial visit date

    // Sort houses based on their endDay in non-decreasing order
    sort(houses.begin(), houses.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    for (int i = 0; i < n; i++) {
        // Assign the current date to the i-th house
        visitDates[i] = currDate;

        // Move to the next date if the maximum number of houses for the current date has been reached
        if ((i + 1) % k == 0 && i + 1 < n) {
            currDate++;
        }
    }

    // Print the visit dates for each house
    for (int i = 0; i < n; i++) {
        cout << visitDates[i] << endl;
    }

    return 0;
}
