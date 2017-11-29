class Solution {
public:
    string reverseString(string s) {
        if(s.size() <= 1){
            return s;
        }
        return s[s.size()-1] + reverseString(s.substr(0, s.size()-1));
    }
};
//The method above cannot pass the last case.

class Solution {
public:
    string reverseString(string s) {
        int len = s.size();
        string str = "";
        for(int i = len - 1; i >=0; --i){
            str += s[i];
        }
        return str;
    }
};