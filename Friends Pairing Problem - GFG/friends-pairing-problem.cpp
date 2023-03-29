//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

// } Driver Code Ends
class Solution
{
public:
int mod=1e9+7;

    long long int solve(int n, long long int dp[])
    {
        if(n<=2) return n;
        if(dp[n] != -1) return dp[n];
        
        long long int a = (((n-1)%mod)*solve(n-2,dp)%mod)%mod;
        long long int b = solve(n-1,dp)%mod;
        return dp[n] = a+b;
    }
    int countFriendsPairings(int n) 
    { 
        // code here
        long long int dp[n+1];
        memset(dp,-1,sizeof(dp));
        return solve(n,dp)%mod;
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
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 

// } Driver Code Ends