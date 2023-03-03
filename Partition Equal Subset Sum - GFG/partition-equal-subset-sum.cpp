//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool solve(int arr[], int n, int idx, int target)
    {
        // base cases
        if(idx >= n) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        
        bool incl = solve(arr,n,idx+1,target - arr[idx]);
        bool excl = solve(arr,n,idx+1,target - 0);
        
        return incl || excl;
    }
    
    bool solveMem(int arr[], int n, int idx, int target, vector<vector<int>> &dp)
    {
        // base cases
        if(idx >= n) return 0;
        if(target<0) return 0;
        if(target==0) return 1;
        if(dp[idx][target] != -1) return dp[idx][target];
        
        bool incl = solveMem(arr,n,idx+1,target - arr[idx], dp);
        bool excl = solveMem(arr,n,idx+1,target - 0, dp);
        
        return dp[idx][target] = incl || excl;
    }
    
    bool solveTab(int arr[], int n, int total)
    {
        vector<vector<int>> dp(n+1, vector<int>(total+1, 0));
        
        for(int i=0;i<=n;i++)
        {
            dp[i][0]=1;
        }
        
        for(int index=n-1;index >=0; index--)
        {
            for(int target=0;target<=total/2;target++)
            {
                bool incl=0;
                if(target-arr[index] >=0) 
                incl = dp[index+1][target - arr[index]];
                
                bool excl = dp[index+1][target - 0];

                dp[index][target] = incl || excl;
            }
        }
        return dp[0][total/2];
    }
    bool solveSpace(int arr[], int n, int total)
    {
        vector<int> curr(total/2 + 1, 0);
        vector<int> next(total/2 + 1, 0);
        
        curr[0]=1;
        next[0]=1;
        
        for(int index=n-1;index >=0; index--)
        {
            for(int target=0;target<=total/2;target++)
            {
                bool incl=0;
                if(target-arr[index] >=0) 
                incl = next[target - arr[index]];
                
                bool excl = next[target - 0];

                curr[target] = incl || excl;
            }
            next=curr;
        }
        return next[total/2];
    }

public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int totalSum=0;
        for(int i=0;i<N;i++)
        {
            totalSum+=arr[i];
        }
        if(totalSum & 1) return 0;
        
        int target = totalSum / 2;
        
        // return solve(arr,N,0,target);
        
        // vector<vector<int>> dp(N, vector<int>(target+1, -1));
        // return solveMem(arr,N,0,target,dp);
        
        // return solveTab(arr,N, totalSum);
        return solveSpace(arr,N, totalSum);
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}
// } Driver Code Ends