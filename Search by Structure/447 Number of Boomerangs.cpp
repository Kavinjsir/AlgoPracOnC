class Solution {
private:
    int len(const pair<int, int> &a, const pair<int, int> &b){
        return (a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second);
    }
public:
    int numberOfBoomerangs(vector<pair<int, int>>& points) {
        
        int res = 0;
        
        for(int i = 0; i < points.size(); ++i){
            unordered_map<int, int>record;
            
            for(int j = 0; j < points.size(); ++j)
                if(j != i)
                    record[len(points[i], points[j])]++;
            for(unordered_map<int, int>::iterator iter = record.begin(); iter != record.end(); iter++)
                res += (iter->second) * (iter->second - 1);
            
        }
        
        return res;
    }
};