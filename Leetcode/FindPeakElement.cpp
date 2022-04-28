// There can be more than one peak elements
// A peak element is the one which is greater than the elements in it's neighbors


// ----------------------------------- Leetcode code as below 




// class Solution {
// public:
//     int findPeakElement(vector<int>& nums) {
        
//         int l = 0;
//         int n = nums.size();
//         int r = nums.size()-1;
//         while(l<=r){
//             int mid = (l+r)/2;
//             if(mid > 0 && mid < n-1 ){
            
//             if((nums[mid] > nums[mid+1]) && (nums[mid] > nums[mid-1])) return mid;
            
//             else if(nums[mid+1] > nums[mid])  l = mid+1;
            
//             else r = mid-1;
            
//         }
//             else if(mid == 0){
//                 if(nums[0] > nums[1]){
//                     return 0;
//                 }
//                 else{
//                     return 1;
//                 }
//             }
//             else if(mid == n-1){
//                 if(nums[n-1] > nums[n-2]){
//                     return (n-1);
//                 }
//                 else{
//                     return (n-2);
//                 }
//             }
//         }
//         return 0;
//     }
// };