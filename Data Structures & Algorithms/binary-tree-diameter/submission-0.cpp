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
private:
    int res=0;
    //returns height
    int dfs(TreeNode* curr)
    {
        if(!curr)
        {
            return 0;
        }
        int left=dfs(curr->left);
        int right=dfs(curr->right);

        int diameter=left+right;
        res=max(res,diameter); //updates the global variable

        int height=max(left,right)+1; //+1 for current node
        return height;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return res;
    }
};
