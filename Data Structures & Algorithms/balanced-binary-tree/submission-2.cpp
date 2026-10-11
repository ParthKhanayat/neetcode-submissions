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

//A BETTER SOLUTION (SAME TIME COMPLEXITY THOUGH)
// WE DON'T WANT VALUES FO HEIGHT, WE JUST NEED TO CHECK, SO WE CAN ALSO PRUNE THE NODES AS SOON AS WE GET UNBALANCED TREE
class Solution {
public:
    int dfs(TreeNode* root)
    {
        if(!root) return 0;
        int leftHeight=dfs(root->left);
        if (leftHeight==-1) return -1;
        int rightHeight=dfs(root->right);
        if(rightHeight==-1) return -1;

        if(abs(leftHeight-rightHeight)>1) return -1;
        int height=max(leftHeight,rightHeight)+1;
        return height;
    }
    bool isBalanced(TreeNode* root) {
        return dfs(root)!=-1;
    }
};
