class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int> >q;
        int i = 0; 
        while(i < k){
            q.push(nums[i++]);
        }
        int len = nums.size(), tmp;
        while(i < len){
            tmp = nums[i++];
            if(tmp > q.top()){
                q.pop();
                q.push(tmp);
            }
        }
        return q.top();
    }
};