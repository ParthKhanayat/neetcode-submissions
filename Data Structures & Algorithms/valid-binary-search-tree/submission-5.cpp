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
    bool valid(TreeNode* root,long long left,long long right)
    {
        if(!root) return true;
        if(!(root->val<right && root->val>left)) return false;
        return valid(root->left,left,root->val) && valid(root->right,root->val,right);
    }
    bool isValidBST(TreeNode* root) {
        return valid(root,LLONG_MIN,LLONG_MAX); //use infinity(min and max of long long) because some numbers are greater than 999999, or less than -999999
    }
};
