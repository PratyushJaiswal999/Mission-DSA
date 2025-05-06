#include <iostream>
#include <vector>
using namespace std;

long candies(int n, vector<int> ratings) {
    vector<long> candy(n, 1);

    // Left to right pass
    for (int i = 1; i < n; ++i) {
        if (ratings[i] > ratings[i - 1]) {
            candy[i] = candy[i - 1] + 1;
        }
    }

    // Right to left pass
    for (int i = n - 2; i >= 0; --i) {
        if (ratings[i] > ratings[i + 1]) {
            candy[i] = max(candy[i], candy[i + 1] + 1);
        }
    }

    long total = 0;
    for (int i = 0; i < n; ++i) {
        total += candy[i];
    }

    return total;
}

int main() {
    int n;
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; ++i) {
        cin >> ratings[i];
    }

    cout << candies(n, ratings) << endl;
    return 0;
}
