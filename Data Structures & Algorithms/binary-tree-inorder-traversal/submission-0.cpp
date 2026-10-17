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
 

 //MORRIS TRAVERSAL TC: O(N) SC:O(1)
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        TreeNode* curr= root;
        while(curr!=nullptr)
        {
            if(curr->left==nullptr) //if no left, then curr is the root
            {
                inorder.push_back(curr->val);
                curr=curr->right;
            }
            else{ //if there exists left, then the last guy of the left subtree should have a thread connected to curr
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr/*it should not point to itself(no thread already present)*/)
            {
                prev=prev->right;
            }
            //CASE 1 : if right comes out to be null
            if(prev->right==nullptr)
            {
                prev->right=curr; //create a thread
                curr=curr->left; //curr can proceed to left
            }
            //CASE 2: if right is connected to curr
            else
            {
                prev->right=nullptr; //cut the thread
                inorder.push_back(curr->val);
                //left side is done, curr you can go to right
                curr=curr->right;
            }

            }
        }
        return inorder;
    }
};