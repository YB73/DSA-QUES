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
class Solution
{
public:
    int ans;
    void solve(TreeNode *root, int mn, int mx)
    {
        if (!root)
            return;
        mn=min(root->val, mn);
        mx=max(root->val, mx);
        ans = max(ans, mx-mn);
        solve(root->left, mn, mx);
        solve(root->right, mn, mx);
    }
    int maxAncestorDiff(TreeNode *root)
    {
        ans = 0;
        solve(root, root->val, root->val);
        return ans;
    }
};