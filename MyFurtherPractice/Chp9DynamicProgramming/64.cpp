//My Solution
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int glen = grid.size(), clen = grid[0].size();
        for(int i = 1; i < clen; ++i){
            grid[0][i] += grid[0][i - 1];
        }
        for(int i = 1; i < glen; ++i){
            grid[i][0] += grid[i - 1][0];
        }
        
        for(int i = 1; i < glen; ++i){
            for(int j = 1; j < clen; ++j){
                grid[i][j] += min(grid[i-1][j], grid[i][j-1]);
            }
        }
        return grid[glen - 1][clen - 1];
    }
};

//Discuss
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for (int i = 1; i < m; i++)
            cur[i] = cur[i - 1] + grid[i][0]; 
        for (int j = 1; j < n; j++) {
            cur[0] += grid[0][j]; 
            for (int i = 1; i < m; i++)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};