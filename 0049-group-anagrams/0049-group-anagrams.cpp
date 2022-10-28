class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        vector<vector<string>> res;
        if(strs.size() == 0){
            return res;
        }
        for(string s : strs){
            string x = s;
            sort(x.begin(), x.end());
            mp[x].push_back(s);
        }
        for(auto it=mp.begin(); it!=mp.end(); it++){
            res.push_back(it->second);
        }
        return res;
    }
};