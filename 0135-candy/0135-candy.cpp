class Solution {
public:
    int candy(vector<int>& ratings) {
//         int size = ratings.size();
//         if(size<=1) return size;
//         vector<int> nums(size,1);
//         for(int i=1; i<size; i++){
//             if(ratings[i] > ratings[i-1]) {
//                 nums[i] = nums[i-1] + 1;
                
//             }
//             if(ratings[i] < ratings[i-1] ){
//                 nums[i-1] = nums[i] + 1;
//             }
//             if(ratings[i] == ratings[i-1]){
//                 nums[i] = max(nums[i], nums[i-1]-1);
//             }
          
            
//         }
//         int res = 0;
//         for(int i=0; i<nums.size(); i++){
//             res += nums[i];
//         }
//         return res+1;
              int n = ratings.size();
        vector<int> candies(n,1);
        int min = 0;
        for(int i=0; i<n-1; i++){
            if(ratings[i] < ratings[i+1]){
                candies[i+1] = candies[i] + 1;
            }
        }
        for(int i=n-1; i>0; i--){
            if(ratings[i-1] > ratings[i] && candies[i-1]<=candies[i]){
                candies[i-1] = candies[i] + 1;
            }
        }
        for(int i=0; i<n; i++){
            min += candies[i];
        }
        return min;
        
    }
};