//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

// } Driver Code Ends
class Solution
{
    // int solve(int arr[], int n)
    // {
    //     if(n<0) return 0;
    //     if(n==0) return arr[0];
        
    //     int include = solve(arr, n-2) + arr[n];
    //     int exclude = solve(arr,n-1) + 0;
        
    //     return max(include,exclude);
    // }
    // int solveMem(int arr[],  vector<int> &dp, int n)
    // {
    //     if(n<0) return 0;
    //     if(n==0) return arr[0];
        
    //     if(dp[n] != -1) return dp[n];
        
    //     int include = solveMem(arr,dp, n-2) + arr[n];
    //     int exclude = solveMem(arr,dp, n-1) + 0;
        
    //     dp[n]=max(include,exclude);
    //     return dp[n];
    // }
    
    // int solveTab(int arr[], int n)
    // {
    //     vector<int> dp(n);
    //     dp[0]= arr[0];
        
    //     for(int i=1;i<n;i++)
    //     {
    //         int incl = dp[i-2]+arr[i];
    //         int excl = dp[i-1]+0;
            
    //         dp[i]=max(incl,excl);
    //     }
        
    //     return dp[n-1];
    // }
    
    int solveSpace(int arr[], int n)
    {
        int prev2 = 0;
        int prev1 = arr[0];
        
        for(int i=1;i<n;i++)
        {
            int incl = prev2+arr[i];
            int excl = prev1+0;
            
            int ans = max(incl,excl);
            prev2=prev1;
            prev1=ans;
        }
        
        return prev1;
    }
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // int ans= solve(arr,n-1);
        // return ans;
        
        // vector<int> dp(n, -1);
        // return solveMem(arr,dp,n-1);
        
        // return solveTab(arr,n);
        
        return solveSpace(arr,n);
    }
};

//{ Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}

// } Driver Code Ends