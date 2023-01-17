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
    void createMapping(vector<int>& inorder, unordered_map<int,int> &nodeToIndex,int n)
    {
        for(int i=0;i<n;i++)
        {
            nodeToIndex[inorder[i]]=i;
        }
    }
    TreeNode* solve(vector<int>& inorder,vector<int>& preorder,int &index,int inorderStart,int inorderEnd,
                int n,unordered_map<int,int> &nodeToIndex)
    {
        //base case
        if(index>=n || inorderStart > inorderEnd)
        {
            return NULL;
        }
        
        int element=preorder[index++];
        TreeNode* root=new TreeNode(element);
        int position=nodeToIndex[element];
        
        //recursive calls
        root->left=solve(inorder,preorder,index,inorderStart,position-1,n,nodeToIndex);
        root->right=solve(inorder,preorder,index,position+1,inorderEnd,n,nodeToIndex);
        
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preorderIndex=0;
        int n=preorder.size();
        unordered_map<int,int> nodeToIndex;
        createMapping(inorder,nodeToIndex,n);
        return solve(inorder,preorder,preorderIndex,0,n-1,n,nodeToIndex);
    }
};