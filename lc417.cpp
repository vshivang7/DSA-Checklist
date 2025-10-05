// 417. Pacific Atlantic Water Flow

// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.
// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).
// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.
// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

class Solution {
public:
    vector<vector<bool>> pac, atl;
    vector<int> dir={-1, 0, 1, 0, -1};
    void dfs(int i, int j, vector<vector<int>>& heights, vector<vector<bool>> &vis){
        int m=heights.size();
        int n=heights[0].size();
        vis[i][j]=true;
        for(int k=0;k<4;k++){
            int ni=i+dir[k], nj=j+dir[k+1];
            if(ni>=0 && nj>=0 && ni<m && nj<n && !vis[ni][nj] && heights[i][j]<=heights[ni][nj]){
                dfs(ni, nj, heights, vis);
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        pac.assign(m, vector<bool>(n, false));
        atl=pac;
        for(int i=0;i<m;i++){
            dfs(i, 0, heights, pac);
            dfs(i, n-1, heights, atl);
        }
        for(int j=0;j<n;j++){
            dfs(0, j, heights, pac);
            dfs(m-1, j, heights, atl);
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j] && atl[i][j])  ans.push_back({i, j});
            }
        }
        return ans;
    }
};
