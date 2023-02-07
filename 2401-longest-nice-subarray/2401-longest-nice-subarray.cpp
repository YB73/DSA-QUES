class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        // using sliding window of variable length 
        //we have to find the maximum window size
        
        int i=0,j=0;
        int num = 0;
        int ans = 0;
        
        //iterate through all the elements
        for(i=0;i<nums.size();i++){
            
            //if at any point a single position has more than 1 bit set
            while((num&nums[i])!=0){
                //unset the bits at that position until & of the two is not equal to 0 again
                num^=nums[j];
                //keep moving the previous end of the window by removing the element from the window
                j++;
            }
            
            //if there is no issue and the & of the numbers is 0
            //keep on setting the bits for that position in num
            num |= nums[i];
            
            //keep count of the maximum window size 
            ans = max(ans, i-j+1);
            
        }
        
        //return maximum window size
        return ans;
    }
};