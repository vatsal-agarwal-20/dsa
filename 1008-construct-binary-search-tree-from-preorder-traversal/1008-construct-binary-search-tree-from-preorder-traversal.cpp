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
    TreeNode* solve(vector<int> &preorder,int mini,int max, int &index)
    {
        if(index >= preorder.size())
            return NULL;
        
        if(preorder[index] < mini || preorder[index] > max)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[index++]);
        root->left= solve(preorder,mini, root->val,index);
        root->right=solve(preorder,root->val,max,index);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int mini=INT_MIN;
        int max=INT_MAX;
        int i=0;
        
        return solve(preorder,mini,max,i);
    }
};