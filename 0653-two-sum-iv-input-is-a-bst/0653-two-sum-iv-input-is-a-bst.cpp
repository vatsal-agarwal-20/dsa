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
    void inorder(TreeNode* root, vector<int> &inorderVal)
    {
        if(root==NULL)
            return;
        
        inorder(root->left,inorderVal);
        inorderVal.push_back(root->val);
        inorder(root->right,inorderVal);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        vector<int> inorderVal;
        inorder(root,inorderVal);
        int i=0;int j= inorderVal.size()-1;
        
        while(i<j)
        {
            if(inorderVal[i]+inorderVal[j] <k)
                i++;
            else if(inorderVal[i]+inorderVal[j] >k)
                j--;
            else 
                return true;
        }
        return false;
    }
};