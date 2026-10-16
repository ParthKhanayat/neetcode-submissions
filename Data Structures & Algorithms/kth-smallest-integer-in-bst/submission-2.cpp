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

//USING MORRIS TRAVERSAL
// TC: O(N) , SC:O(1)
class Solution {
public:
    int count=1;
    int inorder(TreeNode* root,int k)
    {
        TreeNode* curr=root;
        while(curr!=nullptr)
        {
            if(curr->left==nullptr) //no left, curr is root
            {
                if(count==k)
                {
                    return curr->val;
                }
                count++;
                curr=curr->right;
            }
            else{
                TreeNode* prev=curr->left;
                while(prev->right!=nullptr && prev->right!=curr)
                {
                    prev=prev->right;
                }
                //if right comes out to be null(connect thread)
                if(prev->right==nullptr)
                {
                    prev->right=curr;
                    curr=curr->left; //curr can proceed to the left
                }
                //if right comes out to be curr (already thread)
                if(prev->right==curr)
                {
                    prev->right=nullptr; //remove the thread
                    if(count==k) return curr->val;
                    count++;
                    //left side is done, curr can go to the right
                    curr=curr->right;   
                }
            }

        }
    }
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        return inorder(root,k);
    }
};
