#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

int queensAttack(int n, int k, int r_q, int c_q, vector<vector<int>> obstacles) {
    // Direction vectors: (row increment, column increment)
    // 8 directions: top, bottom, left, right, and 4 diagonals
    vector<pair<int, int>> directions = {
        {1, 0}, {-1, 0}, {0, -1}, {0, 1},
        {1, 1}, {1, -1}, {-1, 1}, {-1, -1}
    };

    // Create a set of obstacles for O(1) access
    unordered_map<int, unordered_map<int, bool>> obstacleMap;
    for (auto &obs : obstacles) {
        obstacleMap[obs[0]][obs[1]] = true;
    }

    int count = 0;

    // Explore each direction
    for (auto dir : directions) {
        int r = r_q + dir.first;
        int c = c_q + dir.second;

        while (r >= 1 && r <= n && c >= 1 && c <= n) {
            if (obstacleMap[r][c])
                break;
            count++;
            r += dir.first;
            c += dir.second;
        }
    }

    return count;
}

int main() {
    int n, k;
    cin >> n >> k;
    int r_q, c_q;
    cin >> r_q >> c_q;

    vector<vector<int>> obstacles(k, vector<int>(2));
    for (int i = 0; i < k; i++) {
        cin >> obstacles[i][0] >> obstacles[i][1];
    }

    cout << queensAttack(n, k, r_q, c_q, obstacles) << endl;
    return 0;
}
