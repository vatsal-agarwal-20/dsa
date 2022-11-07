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

/* 
//Method 1

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

*/


//Method 2
void convertIntoSortedDLL(Node* root,Node* &head)
{
    if(root==NULL) return;
    
    convertIntoSortedDLL(root->right,head);
    
    root->right=head;
    
    if(head!=NULL)
        head->left=root;
    
    head=root;
    
    convertIntoSortedDLL(root->left,head);
}

Node* mergeTwoSortedLL(Node* head1, Node* head2)
{
    Node* head=NULL;
    Node* tail=NULL;
    
    while(head1!=NULL && head2!=NULL)
    {
        if(head1->data < head2->data)
        {
            if(head==NULL)
            {
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
            }
        }
        else
        {
            if(head==NULL)
            {
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL)
    {
                tail->right=head1;
                head1->left=tail;
                tail=head1;
                head1=head1->right;
    }
    while(head2!=NULL)
    {
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
    }
    return head;
}

int countNodes(Node* head)
{
    Node* temp=head;
    int n=0;
    while(temp!=NULL)
    {
        temp=temp->right;
        n++;
    }
    return n;
}
Node* sortedLLToBST(Node* &head, int n)
{
    if(n<=0 || head==NULL)
        return NULL;
    
    Node* left=sortedLLToBST(head,n/2);
    
    Node* root=head;
    root->left=left;
    
    head=head->right;
    
    root->right=sortedLLToBST(head,n-n/2-1);
    
    return root;
}


Node *mergeBST(Node *root1, Node *root2)
{
    // Write your code here.

/*
    //Method 1

    // Step 1
    vector<int> m;
    inorder(root1, m);

    vector<int> n;
    inorder(root2, n);

    // Step 2
    vector<int> mergeArray = mergeArrays(m, n);

    // Step 3
    return inorderToBST(mergeArray, 0, mergeArray.size() - 1);

*/

    //Method 2: Using DLL
    
    //Step 1
    Node* head1=NULL;
    convertIntoSortedDLL(root1,head1);
    head1->left=NULL;
    
    Node* head2=NULL;
    convertIntoSortedDLL(root2,head2);
    head2->left=NULL;
    
    //Step 2
    Node* head= mergeTwoSortedLL(head1,head2);
    
    //Step 3
    return sortedLLToBST(head,countNodes(head));
}