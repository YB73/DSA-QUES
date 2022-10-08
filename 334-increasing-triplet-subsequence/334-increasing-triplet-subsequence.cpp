class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int left = INT_MAX, middle = INT_MAX;
        for(auto ni : nums){
            if(left >= ni){
                left=ni;
            }
                else if(middle >= ni){
                    middle = ni;
                }
                else{
                    return true;
                }
            }
        
        return false;
    }
};