class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> record;
        int tmp;
        for(int i = 0; i < nums.size(); ++i){
            tmp = target - nums[i];
            if(record.find(tmp) != record.end()){
                int res[2] = {i, record[tmp]};
                return vector<int>(res, res + 2);
            }
            
            record[nums[i]] = i;
        }
    }
};