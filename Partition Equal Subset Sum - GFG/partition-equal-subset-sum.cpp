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
        
        vector<vector<int>> dp(N, vector<int>(target+1, -1));
        return solveMem(arr,N,0,target,dp);
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