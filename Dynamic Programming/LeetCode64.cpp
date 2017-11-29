class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> res = grid;
        int m = res.size(), n = res[0].size();
        for(int i = 1; i < m; ++i)
            res[i][0] += res[i - 1][0];
        for(int j = 1; j < n; ++j)
            res[0][j] += res[0][j - 1];
        for(int i = 1; i < m; ++i)
            for(int j = 1; j < n; ++j)
                res[i][j] += min(res[i - 1][j], res[i][j - 1]);
        return res[m-1][n-1];
    }
};


//Reference on Discuss
//Very 6666
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<int> cur(m, grid[0][0]);
        for(int i = 1; i < m; ++i)
            cur[i]  = cur[i - 1] + grid[i][0];
        for(int j = 1; j < n; ++j){
            cur[0] += grid[0][j];
            for(int i = 1; i < m; ++i)
                cur[i] = min(cur[i - 1], cur[i]) + grid[i][j];
        }
        return cur[m - 1];
    }
};