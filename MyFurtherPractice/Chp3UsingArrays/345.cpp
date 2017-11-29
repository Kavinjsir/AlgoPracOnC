class Solution {
public:
    string reverseVowels(string s) {
        string vow = "aeiouAEIOU";
        char tmp;
        int i = 0, j = s.size() - 1;
        int l, r;
        while(i < j){
            l = vow.find(s[i]);
            r = vow.find(s[j]);
            if(l != vow.npos && r != vow.npos){
                tmp = s[i];
                s[i] = s[j];
                s[j] = tmp;
                i++;
                j--;
            } else {
                if(l == vow.npos){
                    i++;
                }
                if(r == vow.npos){
                    j--;
                }                
            }
        }
        return s;
    }
};

//https://www.cnblogs.com/web100/archive/2012/12/02/cpp-string-find-npos.html