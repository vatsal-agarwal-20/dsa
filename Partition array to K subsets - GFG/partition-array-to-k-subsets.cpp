//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method */

class Solution{
    bool solve(int a[], int n, int k, vector<int> &vis,int currSum, int sum)
    {
        if(k==1) return 1;
        
        if(currSum > sum) return 0;
        if(currSum == sum)
        {
            return solve(a,n,k-1,vis,0,sum);
        }
        
        for(int i=0;i<n;i++)
        {
            if(vis[i]==0)
            {
                vis[i]=1;
                if(solve(a,n,k,vis,currSum+a[i],sum))
                {
                    return 1;
                }
                vis[i]=0;
            }
        }
        return 0;
    }
  public:
    bool isKPartitionPossible(int a[], int n, int k)
    {
         //Your code here
         int sum=0;
         for(int i=0;i<n;i++)
         {
             sum+=a[i];
         }
         if(k>n || sum%k != 0) return 0;
         
         sum=sum/k;
         vector<int> vis(n,0);
         return solve(a,n,k,vis,0,sum);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	
    	cin>>n;
    	int a[n];
    	for(int i=0;i<n;i++)
    	cin>>a[i];
    	int k;
    	cin>>k;
    	Solution obj;
    	cout<<obj.isKPartitionPossible(a, n, k)<<endl;
    }
}
// } Driver Code Ends