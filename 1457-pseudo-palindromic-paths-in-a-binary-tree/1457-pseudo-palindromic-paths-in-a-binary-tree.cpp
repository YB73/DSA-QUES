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
    int count;
    void solve(TreeNode *root, unordered_map<int, int> &mp, int oc)
    {
        if (!root)
            return;

        mp[root->val]++;
        (mp[root->val] % 2 == 1) ? oc++ : oc--;
        if (!root->left && !root->right)
        {
            if (oc <= 1)
                count++;
        }
        solve(root->left, mp, oc);
        solve(root->right, mp, oc);
        mp[root->val]--;
        return;
    }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        unordered_map<int, int> mp;
        count = 0;
        solve(root, mp, 0);
        return count;
    }
};