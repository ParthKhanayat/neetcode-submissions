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

//USING INORDER TRAVERSAL(ALWAYS IN ASC SORTED ORDER:property of BST)
// TC: O(N) , SC: O(N)
class Solution {
public:
    int count=1;
    int res=0;
    void inorder(TreeNode* root,int k)
    {
        if(!root) return;
        inorder(root->left,k);
        if(count==k) res=root->val;
        count++;
        inorder(root->right,k);
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        inorder(root,k);
        return res;
    }       
};
