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
    int count=0;
    // int maxa=-9999999; maxa should not be shared, maxa can be different for different subtrees
    void dfs(TreeNode* root,int maxa)
    {
        if(!root) return;
        if(root->val>=maxa)
        {
            maxa=root->val;
            count++;
        }
        dfs(root->left,maxa);
        dfs(root->right,maxa);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        dfs(root,-999999);
        return count;
    }
};
