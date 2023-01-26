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
    int i=0;
    TreeNode* bstFromPreorder(vector<int>& preorder, int parentVal=INT_MAX) {
        
        if(i >= preorder.size() || preorder[i] > parentVal)
        {
            return NULL;
        }
        int currVal = preorder[i++];
        TreeNode* temp = new TreeNode(currVal);
        
        temp->left = bstFromPreorder(preorder, currVal);
        temp->right= bstFromPreorder(preorder, parentVal);
        
        return temp;
    }
};