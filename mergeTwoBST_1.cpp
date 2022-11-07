#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

struct Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = NULL;
    }

    ~Node()
    {
        if (left)
        {
            delete left;
        }

        if (right)
        {
            delete right;
        }
    }
};

void inorder(Node *root, vector<int> &in)
{
    if (root == NULL)
        return;

    inorder(root->left, in);
    in.push_back(root->data);
    inorder(root->right, in);
}

vector<int> mergeArrays(vector<int> &a, vector<int> &b)
{
    vector<int> ans(a.size() + b.size());
    int i = 0, j = 0, k = 0;
    while (i < a.size() && j < b.size())
    {
        if (a[i] <= b[j])
        {
            ans[k++] = a[i];
            i++;
        }
        else
        {
            ans[k++] = b[j];
            j++;
        }
    }
    while (i < a.size())
    {
        ans[k++] = a[i];
        i++;
    }
    while (j < b.size())
    {
        ans[k++] = b[j];
        j++;
    }
    return ans;
}
Node *inorderToBST(vector<int> &in, int s, int e)
{
    if (s > e)
        return NULL;
    int mid = (s + e) / 2;

    Node*root = new Node(in[mid]);
    root->left = inorderToBST(in, s, mid - 1);
    root->right = inorderToBST(in, mid + 1, e);
    return root;
}
Node *mergeBST(Node *root1, Node *root2)
{
    // Write your code here.

    // Step 1
    vector<int> m;
    inorder(root1, m);

    vector<int> n;
    inorder(root2, n);

    // Step 2
    vector<int> mergeArray = mergeArrays(m, n);

    // Step 3
    return inorderToBST(mergeArray, 0, mergeArray.size() - 1);
}