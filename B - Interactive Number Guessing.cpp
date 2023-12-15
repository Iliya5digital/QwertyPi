#include <iostream>
#include <vector>

using namespace std;

int digitSum(long long num) {
    int sum = 0;
    while (num > 0) {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main() {
    long long secretNumber = 0;

    // Perform the initial query
    cout << "query 0" << endl;
    cout.flush();
    int initialSum;
    cin >> initialSum;

    // Deduce the value of the secret number
    secretNumber = initialSum;

    // Determine the increment value for queries
    long long increment = 1;
    for (int i = 0; i < 18; i++) {
        cout << "query " << increment << endl;
        cout.flush();
        int sum;
        cin >> sum;
        secretNumber += static_cast<long long>(sum - initialSum) * increment;
        increment *= 10;
        initialSum = sum;
    }

    // Send the answer
    cout << "answer " << secretNumber << endl;
    cout.flush();

    return 0;
}
