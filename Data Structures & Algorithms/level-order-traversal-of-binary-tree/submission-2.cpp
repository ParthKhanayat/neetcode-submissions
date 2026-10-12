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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty())
        {
            vector<int>level;
            int size=q.size();
            //keep adding element to sublist until q(at that instant) is empty
            for(int i=size;i>0;i--)
            {
                TreeNode* node=q.front();
                q.pop();
                //when you pop, you also add it's children back to queue,but our og queue size is preserved in size (basically a snapshot)
                if(node)
                {
                    level.push_back(node->val);
                    q.push(node->left);
                    q.push(node->right);
                }
            }
            if(!level.empty())
            {
                res.push_back(level);
            }
        }
        return res;
    }
};
