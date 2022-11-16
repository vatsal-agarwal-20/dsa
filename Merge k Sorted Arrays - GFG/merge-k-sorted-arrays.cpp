//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


// } Driver Code Ends
//User function Template for C++
class node{
    public:
    int data;
    int i;
    int j;
    
    node(int val,int a,int b)
    {
        data=val;
        i=a;
        j=b;
    }
};
class compare{
    public:
    bool operator()(node* a,node* b)
    {
        return a->data > b->data;
    }
};
class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        //code here
        
        // we created a custom data type for minheap therefore instead of greater<int>
        // we create a custom class "compare"
        priority_queue<node*,vector<node*>,compare> pq;
        
        // Step 1: saare arrays ke first element ko minheap mein add krdo
        for(int i=0;i<K;i++)
        {
            node* temp=new node(arr[i][0],i,0);
            pq.push(temp);
        }
        
        // Step 2:
        vector<int> ans;
        
        while(pq.size()>0)
        {
         node* temp=pq.top();
         ans.push_back(temp->data);
         pq.pop();
         
         int i=temp->i;
         int j=temp->j;
         
         if(j+1 < arr[i].size())
         {
             node* next = new node(arr[i][j+1],i,j+1);
             pq.push(next);
         }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(k, vector<int> (k, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}






// } Driver Code Ends