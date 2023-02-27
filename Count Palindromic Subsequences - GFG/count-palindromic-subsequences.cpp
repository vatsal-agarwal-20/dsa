//{ Driver Code Starts
// Counts Palindromic Subsequence in a given String
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    #define mod 1000000007
    long long int dp[1001][1001];
    
    long long int solve(int i, int j, string &s)
    {
        if(i > j) return 0;
        if(i == j) return 1;
        
        if(dp[i][j] != -1) return dp[i][j];
        
        if(s[i] == s[j])
        {
            return dp[i][j] = (solve(i+1,j,s)%mod + solve(i,j-1,s)%mod + 1 + mod) % mod;
        }
        else
        {
            return dp[i][j] = (solve(i+1,j,s)%mod + solve(i,j-1,s)%mod - solve(i+1,j-1,s)%mod + mod) % mod;
        }
    }
    
    
    long long int  countPS(string str)
    {
       //Your code here
       int n= str.length();
       dp[n][n];
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               dp[i][j]= -1;
           }
       }
       
       return solve(0,n-1,str)%mod;
    }
     
};

//{ Driver Code Starts.
// Driver program
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        Solution ob;
        long long int ans = ob.countPS(str);
        cout<<ans<<endl;
    } 
}
// } Driver Code Ends