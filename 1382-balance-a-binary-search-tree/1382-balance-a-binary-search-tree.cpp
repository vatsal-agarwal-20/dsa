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
    void inorder(TreeNode* root, vector<int> &in)
    {
        if(root==NULL) return;
        
        inorder(root->left,in);
        in.push_back(root->val);
        inorder(root->right,in);
    }
    
    TreeNode* balance(vector<int> in,int s, int e)
    {
        if(s>e)
            return NULL;
        
        int mid= (s+e)/2;
        TreeNode* root=new TreeNode(in[mid]);
        root->left = balance(in,s,mid-1);
        root->right = balance(in,mid+1,e);
        return root;
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> in;
        inorder(root,in);
        
        return balance(in,0,in.size()-1);
    }
};