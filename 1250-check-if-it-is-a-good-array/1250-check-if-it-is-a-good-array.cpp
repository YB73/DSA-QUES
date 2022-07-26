class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
         int gcd = nums[0];
    for(int i=1; i<nums.size(); i++) {
        gcd = __gcd(gcd, nums[i]);

    }
    if(gcd == 1){
        return true;
    }
    return false;
    }
};