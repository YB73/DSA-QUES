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
    vector<vector<int>> levelOrder(TreeNode* root) {
           if(root == NULL){
        return{};
    }
    queue<TreeNode*> q;
    vector<vector<int>> ans;
    q.push(root);
    while(!q.empty()){
        int levelSize = q.size();
        vector<int> currentLevel;
        for(int i=0; i<levelSize; i++){
            auto node = q.front();
            q.pop();
            if(node -> left){
                q.push(node -> left);
            }
            if(node -> right){
                q.push(node -> right);
            }
            currentLevel.push_back(node -> val);
        }
        ans.push_back(currentLevel);
    }
    return ans;
    }
};