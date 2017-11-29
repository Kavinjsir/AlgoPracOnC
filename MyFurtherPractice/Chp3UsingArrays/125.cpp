class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0, j = s.size() - 1;
        char tmp;
        if(j == -1) return true;
        
        vector<char> record;
        for(; i <= j; ++i){
            tmp = s[i];
            if(tmp >= 'a' && tmp <= 'z'){
                record.push_back(tmp);
            } else if(tmp >= '0' && tmp <= '9') {
                record.push_back(tmp);
            } else if(tmp >= 'A' && tmp <= 'Z') {
                record.push_back(tmp + 32);
            }
        }
        i = 0;
        j = record.size() - 1;
        while(i < j){
            if(record[i++] != record[j--]){
                return false;
            } 
        }
        return true;
    }
};