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

//MUCH CLEANER REFINED VERSION OF MY SOLUTION
class Solution {
public:
    //no need for other function, isSameTree can do it itself

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && !q) return true; //true value propogates gack from the bottom, therefore no need for explicitaly creating default true value
        if(!p || !q) return false;
        if(p->val!=q->val) return false; //base case

        return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);


    }
};
