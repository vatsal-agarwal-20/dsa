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
    TreeNode* insertIntoBST(TreeNode* root,int d)
    {
        if(root==NULL)
        {
            root=new TreeNode(d);
            return root;
        }
        if(d> root->val)
        {
            root->right= insertIntoBST(root->right,d);
        }
        else
        {
            root->left= insertIntoBST(root->left,d);
        }
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        // sort(preorder.begin(),preorder.end());
        TreeNode* root=NULL;
        for(int i=0;i<preorder.size();i++)
        {
            root = insertIntoBST(root,preorder[i]);
        }
        return root;
    }
};