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
    TreeNode* solve(vector<int> &preorder,int max, int &index)
    {
        
        if(index >= preorder.size() || preorder[index] > max)
            return NULL;
        
        TreeNode* root=new TreeNode(preorder[index++]);
        root->left= solve(preorder, root->val,index);
        root->right=solve(preorder,max,index);
        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        
        return solve(preorder,INT_MAX,i);
    }
};