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
   void inorder(TreeNode* root, vector<int> &ans)
    {
        if(root == NULL)
        {
            return;
        }
        
        inorder(root->left, ans);
        
        ans.push_back(root->val);
        
        inorder(root->right, ans);
    }
    
    vector<int> findMode(TreeNode* root) {
        
        vector<int> ans;
        map<int, int> m;
        int temp = INT_MIN;
        
        if(root->val == 0)
        {
            return {0};
        }
        
        inorder(root, ans);
        
        for(int i:ans)
        {
            m[i]++;
        }
        
        ans.clear();
        
        for(auto i = m.begin(); i != m.end(); i++)
        {
            temp = max(i->second, temp);
        }
        
        for(auto i = m.begin(); i != m.end(); i++)
        {
            if(i->second == temp)
            {
                ans.push_back(i->first);
            }
        }
        
        return ans;
    }
};