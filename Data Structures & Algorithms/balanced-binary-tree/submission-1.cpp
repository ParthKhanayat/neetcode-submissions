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

//I DID THIS MYSLEF
class Solution {
public:
    bool res=true;
    int dfs(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        int leftHeight=dfs(root->left);
        int rightHeight=dfs(root->right);
        if(abs(leftHeight-rightHeight)>1) res=false;
        int height=max(leftHeight,rightHeight)+1;

        return height;
    }
    bool isBalanced(TreeNode* root) {
        dfs(root);
        return res;

    }
};
