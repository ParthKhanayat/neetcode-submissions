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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "";
        string s="";
        //USING LEVEL ORDER
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr=q.front();
            q.pop();
            if(curr==nullptr) s.append("#,"); //using # for null nodes
            else s.append(to_string(curr->val)+',');
            //in normal level order we check whether the children are null, but here we are allowing null to be added, because we need #, it is already handled at line 27 in next iteration
            if(curr)
            {
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0) return nullptr;
        stringstream s(data); //allow us to do cool stuff
        string str; //current string(keeps updating in our ques)
        getline(s,str,','); //getline(stream,string,delimiter) GOT ROOT
        //"a,b,c" -> "a"
        TreeNode* root= new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* node=q.front();
            q.pop();
            //left child
            getline(s,str,','); //REMEMBER deliminator is char
            if(str=="#") node->left=nullptr;
            else
            {
                TreeNode* leftNode=new TreeNode(stoi(str));
                node->left=leftNode;
                q.push(leftNode); //notice we are only pushing nodes to queue when they exists, we are not pushing null because we can't expand it
            }
            //right child
            getline(s,str,',');
            if(str=="#") node->right=nullptr;
            else
            {
                TreeNode* rightNode=new TreeNode(stoi(str));
                node->right=rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};
