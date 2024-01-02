class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans(1);
        unordered_map<int, int> mp;
        // int i=0;
        for(int x: nums){
            if(!mp.count(x)){
                ans[0].push_back(x);
                mp[x]=0;
            }
            else{
                int idx=mp[x];
                idx++;
                if(idx==ans.size())
                    ans.push_back({x});
                else
                    ans[idx].push_back(x);
                mp[x]=idx;
            }
        }
        return ans;
    }
};