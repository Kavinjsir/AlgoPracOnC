class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int bottom = triangle.size() - 1;
        int up, len;
        for(; bottom > 0; --bottom){
            up = bottom - 1;
            len = triangle[up].size();
            for(int i = 0; i < len; ++i){
                triangle[up][i] += min(triangle[bottom][i], triangle[bottom][i + 1]);
            }
        }
        return triangle[0][0];
    }
};