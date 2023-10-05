class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int thres = nums.size()/3;
        vector<int> res;
        for(auto it : mp){
            if(it.second > thres){
                res.push_back(it.first);
            }
        }
        return res;
    }
};