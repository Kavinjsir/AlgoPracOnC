class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int i = l, j = r;
        int res = (r - l) * min(height[l], height[r]);
        while(l < r){
            if(height[l] < height[r]){
                while(i < r){
                    if(height[i] <= height[l]){
                        i++;
                    } else {
                        break;
                    }
                }
                res = max(res, (r - i) * min(height[i], height[r]));
                l = i;
            } else {
                while(j > l){
                    if(height[j] <= height[r]){
                        j--;
                    } else {
                        break;
                    }
                }
                res = max(res, (j - l) * min(height[j], height[l]));
                r = j;
            }
        }
        return res;
    }
};