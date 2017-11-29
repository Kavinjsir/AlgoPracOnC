class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1){
            return len;
        }
        int i = 0;
        if(nums[i] == nums[i+1]){
            i++;
        }
        int j = i + 1;
        while(j < len){
            if(nums[j] == nums[i]){
                j++;
            } else {
                nums[++i] = nums[j++];
                if(j < len && nums[i] == nums[j]){
                    nums[++i] = nums[j++];
                }
            }
        }
        return ++i;
    }
};