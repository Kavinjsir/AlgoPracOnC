// Reference
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flag[256] = {0};
        int l = 0, r = -1, len = 0;
        while(l < s.size()){
            if(r + 1 < s.size() && flag[s[r+1]] == 0)
                flag[s[++r]]++;
            else
                flag[s[l++]]--;
            len = max(len, r - l + 1);
        } 
        return len;
    }
};

// My implementation
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int flag[256] = {0};
        int maxLen = 0, strLen = s.size();
        int i = 0, j = 0;
        while(j < strLen){
            if(flag[s[j]] == 0){
                flag[s[j++]] = 1;
                maxLen = max(maxLen, j-i);
            } else {
                flag[s[i++]] = 0;
            }
        }
        return maxLen;
    }
};

// Discussion
int lengthOfLongestSubstring(string s) {
        vector<int> dict(256, -1);
        int maxLen = 0, start = -1;
        for (int i = 0; i != s.length(); i++) {
            if (dict[s[i]] > start)
                start = dict[s[i]];
            dict[s[i]] = i;
            maxLen = max(maxLen, i - start);
        }
        return maxLen;
    }

// My further implementation
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> flag(256,-1);
        int j = -1, ml = 0, len = s.length(), i = 0;
        while(i != len){
            if(flag[s[i]] > j)
                j = flag[s[i]];
            flag[s[i]] = i;
            ml = max(ml, i - j);
            i++;
        }
        return ml;
    }
};