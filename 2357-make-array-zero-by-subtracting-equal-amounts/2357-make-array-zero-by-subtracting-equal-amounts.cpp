class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int x;
     int op = 0;
     sort(nums.begin(), nums.end());
     if(nums.size() == 0){
        return 0;
     }
     if(nums.size() == 1 &&  nums[0] == 0){
        return 0;
     }
     for(int i=0; i<nums.size(); i++){
        if(nums[i] > 0){
            x = nums[i];
            op++;
            for(int j=i;j<nums.size();j++){
                if(nums[j] > 0){
                    nums[j] = nums[j] - x;
                }
            }
        }
     }
     
    return op;
    }
};