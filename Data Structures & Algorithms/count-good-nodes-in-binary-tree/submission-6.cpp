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
            maxa=root->val; //the function will update it's copy for maxa
            count++;
        }
        dfs(root->left,maxa);
        //agar maxa global hota toh ye right side wala recursion left ki updated maxa value le leta, fir sabh gadbad ho jaati, we only want the current root maxa value
        dfs(root->right,maxa);
    }
    int goodNodes(TreeNode* root) {
        if(!root) return 0;
        dfs(root,-999999); //only the very first call starts with -99999
        return count;
    }
};
