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
    long long inf = 1e18;
    bool is_valid(TreeNode *root, long L, long R){
        if(root == NULL){
            return true;
        }
        
        if((root->val < R) && (root->val > L)){
            return is_valid(root->left, L, root->val) && is_valid(root->right, root->val, R);
        }
        else{
            return false;
        }
        
        
    }
    bool isValidBST(TreeNode* root) {
        return is_valid(root, LONG_MIN, LONG_MAX);
        
    }
};