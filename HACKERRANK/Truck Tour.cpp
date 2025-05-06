#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long petrol[n], distance[n];
    for (int i = 0; i < n; i++) {
        cin >> petrol[i] >> distance[i];
    }

    int start = 0;
    long long total = 0, tank = 0;

    for (int i = 0; i < n; i++) {
        tank += petrol[i] - distance[i];
        total += petrol[i] - distance[i];

        // If tank goes negative, cannot start from 'start'
        if (tank < 0) {
            start = i + 1;
            tank = 0;
        }
    }

    if (total >= 0)
        cout << start << endl;
    else
        cout << -1 << endl;

    return 0;
}
