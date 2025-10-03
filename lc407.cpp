// 407. Trapping Rain Water II

// Given an m x n integer matrix heightMap representing the height of each unit cell in a 2D elevation map, return the volume of water it can trap after raining.

//   Example 1:
// Input: heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
// Output: 4
// Explanation: After the rain, water is trapped between the blocks.
// We have two small ponds 1 and 3 units trapped.
// The total volume of water trapped is 4.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        typedef pair<int, pair<int, int>> TRI;
        vector<vector<int>> directions = {{-1, 0}, {0, 1}, {0, -1}, {1, 0}};

        int m = heightMap.size();
        if (m == 0) return 0; // Edge case: empty heightMap
        int n = heightMap[0].size();
        if (n == 0) return 0; // Edge case: empty rows

        priority_queue<TRI, vector<TRI>, greater<>> pos; // Min-heap
        vector<vector<bool>> visited(m, vector<bool>(n, false));

        // Add the boundary cells to the priority queue
        for (int i = 0; i < m; i++) {
            pos.push({heightMap[i][0], {i, 0}});
            pos.push({heightMap[i][n - 1], {i, n - 1}});
            visited[i][0] = visited[i][n - 1] = true;
        }
        for (int j = 0; j < n; j++) {
            pos.push({heightMap[0][j], {0, j}});
            pos.push({heightMap[m - 1][j], {m - 1, j}});
            visited[0][j] = visited[m - 1][j] = true;
        }

        int water = 0;
        while (!pos.empty()) {
            TRI curr = pos.top();
            pos.pop();

            int height = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;

            // Explore the 4 possible directions
            for (vector<int>& dir : directions) {
                int ni = i + dir[0];
                int nj = j + dir[1];

                // Check bounds and if the cell is not visited
                if (ni >= 0 && nj >= 0 && ni < m && nj < n && !visited[ni][nj]) {
                    // Calculate trapped water
                    water += max(0, height - heightMap[ni][nj]);
                    // Push the cell into the priority queue with the updated height
                    pos.push({max(height, heightMap[ni][nj]), {ni, nj}});
                    visited[ni][nj] = true;
                }
            }
        }

        return water;
    }
};
