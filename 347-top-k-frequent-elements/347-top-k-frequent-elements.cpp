class Solution {
public:
    static bool cmp(pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
}
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(int i=0; i<nums.size(); i++){
            m[nums[i]]++;
        }
       vector<pair<int,int>> v;
       for(auto i : m){
        v.push_back(i);

       }
         sort(v.begin(), v.end(), cmp);
         
         
         vector<int> ans;
            for(int i=0; i<k; i++){
                ans.push_back(v[i].first);
            }
            return ans;
    }
};