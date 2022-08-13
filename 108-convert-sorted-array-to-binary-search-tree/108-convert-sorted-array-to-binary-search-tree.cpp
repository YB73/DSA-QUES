/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode *sortedArrtoBST(vector<int>&arr, int start, int end){
        if(start > end){
            return NULL;
        }
        int mid = (start+end)/2;
        TreeNode *temp = new TreeNode(arr[mid]);
        temp->left = sortedArrtoBST(arr, start, mid-1);
        
        temp->right = sortedArrtoBST(arr, mid+1, end);
        
        
        return temp;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrtoBST(nums, 0, nums.size()-1);
        
    }
};