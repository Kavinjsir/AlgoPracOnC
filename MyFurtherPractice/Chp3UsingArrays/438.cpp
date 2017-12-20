class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> pv(256, 0), sv(256, 0), res;
        int i = 0, sl = s.size(), pl = p.size();
        if(sl < pl)
            return res;
        for(; i < pl; ++i){
            ++pv[p[i]];
            ++sv[s[i]];
        }
        if(sv == pv)
            res.push_back(0);
        for(; i < sl; ++i){
            ++sv[s[i]];
            --sv[s[i - pl]];
            if(sv == pv)
                res.push_back(i - pl + 1);
        }
        return res;
    }
};