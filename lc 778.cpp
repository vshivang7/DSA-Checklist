// 778. Swim in Rising Water

// You are given an n x n integer matrix grid where each value grid[i][j] represents the elevation at that point (i, j).

// It starts raining, and water gradually rises over time. At time t, the water level is t, meaning any cell with elevation less than equal to t is submerged or reachable.

// You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distances in zero time. Of course, you must stay within the boundaries of the grid during your swim.

// Return the minimum time until you can reach the bottom right square (n - 1, n - 1) if you start at the top left square (0, 0).

class DisjointSet {
public:
    vector<int> size, par;
    DisjointSet(int V) {
        size.resize(V + 1, 1);
        par.resize(V + 1);
        for (int i = 0; i <= V; i++) {
            par[i] = i;
        }
    }
    int findUltPar(int node) {
        if (par[node] == node) return node;
        return par[node] = findUltPar(par[node]);
    }
    void unionBySize(int u, int v) {
        int pu = findUltPar(u);
        int pv = findUltPar(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) {
            par[pu] = pv;
            size[pv] += size[pu];
        } else {
            par[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
class Solution {
public:
    bool isPoss(int limit, vector<vector<int>>& grid){
        int n=grid.size();
        DisjointSet ds(n*n);
        vector<int> dir={-1, 0, 1, 0, -1};
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > limit) continue;

                for (int d = 0; d < 4; d++) {
                    int ni = i + dir[d], nj = j + dir[d + 1];
                    if (ni >= 0 && nj >= 0 && ni < n && nj < n && grid[ni][nj] <= limit) {
                        int u = i * n + j;
                        int v = ni * n + nj;
                        ds.unionBySize(u, v);
                    }
                }
            }
        }
        return ds.findUltPar(0)==ds.findUltPar(grid.size()*grid.size()-1);
    }
    int swimInWater(vector<vector<int>>& grid) {
        int low=0, high=INT_MIN;
        int n=grid.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                high=max(high, grid[i][j]);
            }
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(isPoss(mid, grid)){
                ans=mid;
                high=mid-1;
            }
            else    low=mid+1;
        }
        return ans;
    }
};
