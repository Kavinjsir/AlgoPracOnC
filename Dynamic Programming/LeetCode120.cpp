class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int len = triangle.size() - 1;
        if(len == 0) return triangle[0][0];
        vector<vector<int>> res = triangle;
        
        for(int i = 1; i <= len; ++i){
            res[i][0] += res[i - 1][0];
            res[i][res[i].size() - 1] += res[i - 1][res[i - 1].size() - 1];
            for(int j = 1; j < res[i].size() - 1; ++j)
                res[i][j] += min(res[i - 1][j - 1], res[i - 1][j]);
        }
        int minSum = res[len][0];
        for(int i = 1; i < res[len].size(); ++i)
            minSum = min(minSum, res[len][i]);
        
        return minSum;
    }
};

//Reference in Discuss.
//Very 66666
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> res(triangle.back());
        for(int i = n - 2; i >=0; --i){
            for(int j = 0; j <= i; ++j)
                res[j] = min(res[j], res[j + 1]) + triangle[i][j];
        }
        return res[0];
    }
};