class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
      int i=0, j=0;
    unordered_map<int, int> m;
    while(j<nums.size()){
        
        if(j > k){
            m[nums[i++]]--;
        }
        if(m[nums[j]] > 0 ){
            return true;
        }
        m[nums[j++]]++;

    }
    return false;
    }
};