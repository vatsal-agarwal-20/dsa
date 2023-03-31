//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    int dp[10005];
    int solve(int n, int x, int y, int z)
    {
        if(n==0) return 0;
        
        if(dp[n] != -1) return dp[n];
        
        int op1=INT_MIN,op2=INT_MIN,op3=INT_MIN;
        if(n>=x) op1=solve(n-x,x,y,z);
        if(n>=y) op2=solve(n-y,x,y,z);
        if(n>=z) op3=solve(n-z,x,y,z);
        
        return dp[n] = 1 + max(op1,max(op2,op3));
    }
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        memset(dp,-1,sizeof(dp));
        
        int ans = solve(n,x,y,z);
        if(ans<0) return 0;
        
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}
// } Driver Code Ends