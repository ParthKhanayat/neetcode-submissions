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

//THIS IS SO EASY ONCE YOU GET IT
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return nullptr;
        int currVal=root->val;
        if(p->val<currVal && q->val<currVal) //that means, both lie in the left
        {
            return lowestCommonAncestor(root->left,p,q);
        }

        if(p->val>currVal && q->val>currVal) //that means, both lie in the right
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        return root;
        
    }
};
