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
    int count = 0;
    pair<int, int> dfst(TreeNode* root){
        if(root == NULL){
            return {0,0};
        }
        pair<int, int> leftN = dfst(root->left);
        pair<int, int> rightN = dfst(root->right);
        int nodeS = root->val + leftN.first + rightN.first;
        int nodeC = 1 + leftN.second + rightN.second;
        
        if(root->val == nodeS/(nodeC)){
            count++;
        }
        
        return {nodeS, nodeC};
        
    }
    int averageOfSubtree(TreeNode* root) {
        dfst(root);
        return count;
    }
};