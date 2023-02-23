//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    // int solveRec(int coins[], int x, int n)
    // {
    //     if(x==0)
    //     return 0;
        
    //     if(x<0)
    //     return INT_MAX;
        
    //     int mini= INT_MAX;
    //     for(int i=0;i<n;i++)
    //     {
    //         int ans= solveRec(coins,x-coins[i],n);
    //         if(ans != INT_MAX)
    //         {
    //             mini= min(mini, 1+ ans);
    //         }
    //     }
    //     return mini;
    // }
    
    int solveMem(int coins[], vector<int> &dp, int x, int n)
    {
        if(x==0)
        return 0;
        
        if(x<0)
        return INT_MAX;
        
        if(dp[x] != -1)
        return dp[x];
        
        int mini= INT_MAX;
        for(int i=0;i<n;i++)
        {
            int ans= solveMem(coins,dp,x-coins[i],n);
            if(ans != INT_MAX)
            {
                mini= min(mini, 1+ ans);
            }
        }
        dp[x]=mini;
        return mini;
    }

	public:
	int minCoins(int coins[], int M, int V) 
	{ 
	    // Your code goes here
	   // int ans= solveRec(coins,V,M);
	   // if(ans==INT_MAX) return -1;
	    
	   // return ans;
	   
	   vector<int> dp(V+1, -1);
	   int ans= solveMem(coins,dp,V,M);
	   
	   if(ans== INT_MAX) return -1;
	   else return ans;
	} 
	  
};

//{ Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int v, m;
        cin >> v >> m;

        int coins[m];
        for(int i = 0; i < m; i++)
        	cin >> coins[i];

      
	    Solution ob;
	    cout << ob.minCoins(coins, m, v) << "\n";
	     
    }
    return 0;
}

// } Driver Code Ends