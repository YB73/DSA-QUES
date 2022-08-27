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
    vector<int> ans;
    void inorderTraversal(TreeNode* root) {
        
        if(root == NULL){
            return;
        }
        else{ 
        inorderTraversal(root->left);
        ans.push_back(root->val);
        inorderTraversal(root->right);
        
        }
    }
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }
        inorderTraversal(root);
        int s = 0, e = ans.size() - 1;
        while(s < e){
            int sum = ans[s] + ans[e];
            if(sum == k){
                return true;
            }
            else if(sum > k){
                e--;
            }
            else{
                s++;
            }
        }
        return false;
    }
};