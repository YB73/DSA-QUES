// Subsets



// class Solution {
// public:
//     vector<vector<int>> v;
//     void solve(vector<int>& x, int i, vector<int>&arr){
//         if(i == arr.size()){
//             v.push_back(x);
//             return;
//         }
//         solve(x, i+1, arr);
//         x.push_back(arr[i]);
//         solve(x, i+1, arr);
//         x.pop_back();
        
//     }
//     vector<vector<int>> subsets(vector<int>& nums) {
//         vector<int> x;
//         solve(x, 0, nums);
//         return v;
//     }
// };