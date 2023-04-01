//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
    int solve(int a[], int n, int i, int prev,vector<vector<int>> &dp)
    {
        if(i==n)
        {
            return 0;
        }
        if(dp[i][prev+1] != -1) return dp[i][prev+1];
        
        int len = 0 + solve(a,n,i+1,prev,dp);
        if(prev== -1 || a[i] > a[prev])
        {
            len = max(len, 1 + solve(a,n,i+1,i,dp));
        }
        
        return dp[i][prev+1] = len;
    }
    public:
    //Function to find length of longest increasing subsequence.
    int longestSubsequence(int n, int a[])
    {
       // your code here
       vector<vector<int>> dp(n,vector<int>(n+1,-1));
       
       return solve(a,n,0,-1,dp);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];
        Solution ob;
        //calling method longestSubsequence()
        cout << ob.longestSubsequence(n, a) << endl;
    }
}

// } Driver Code Ends