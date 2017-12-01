//My Solution
class Solution {
public:
    int integerBreak(int n) {
        vector<int> record(n+1, 0);
        record[2] = 1;
        int x, y;
        for(int i = 3; i <= n; ++i){
            for(int j = 1; j <= i/2; ++j){
                x = max(j, record[j]);
                y = max(i - j, record[i - j]);
                record[i] = max(record[i], x * y);
            }
        }
        return record[n];
    }
};

// Course Solution
class Solution { 
public:
    int integerBreak(int n) {
        vector<int> memo(n + 1, -1);
        for(int i = 2; i <= n; ++i){
            for(int j = 1; j <= i - 1; ++j)
                memo[i] = max(memo[i], max(j * (i - j), j * memo[i - j]));
        }
        return memo[n];
    }
};