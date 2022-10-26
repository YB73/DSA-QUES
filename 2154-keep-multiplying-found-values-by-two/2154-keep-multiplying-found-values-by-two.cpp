class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_map<int, int> mp;
        int x = original;
        for(int i=0; i<nums.size(); i++){
            mp[nums[i]]++;
        }
        for(int i=0; i<nums.size(); i++){
            
            if(mp.find(x) != mp.end()){
                x = 2*x;
            }
            
            else{
                break;
            }
            
        }
        return x;
    }
};