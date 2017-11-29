class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int l = 0, r = 0, res = 0, len = nums.size() + 1, minlen = nums.size() + 1;
        while(r <= len){
            if(res < s){
                if(r < len - 1){
                    res += nums[r++];
                } else {
                    break;
                }
            } else {
                minlen = min(minlen, r - l);
                res -= nums[l++];
            }
        }
        return minlen == len ? 0 : minlen;
    }
};