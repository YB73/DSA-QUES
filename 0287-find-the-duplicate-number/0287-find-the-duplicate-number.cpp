class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        int ans;
        for(auto it : mp){
            if(it.second > 1){
                ans = it.first;
                break;
            }
        }
        return ans;
    }
};