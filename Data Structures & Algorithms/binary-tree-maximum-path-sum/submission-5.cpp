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
    int maxa=INT_MIN;
    int maxSum(TreeNode* root)
    {
        if(!root) return 0;
        int left=max(0,maxSum(root->left)); //adding this handles -ve child nodes
        int right=max(0,maxSum(root->right));
        //this was redundant

        // if(root->left==nullptr && root->right==nullptr)
        // {
        //     maxa=max(maxa,root->val);
        //     return root->val;
        // }
        int max1=left+root->val+right;
        maxa=max(maxa,max1);
        return root->val+max({left,right,0});
    }
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;
        maxSum(root);
        return maxa;
    }
};
