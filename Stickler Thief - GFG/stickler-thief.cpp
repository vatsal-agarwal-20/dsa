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
    int solveMem(int arr[],  vector<int> &dp, int n)
    {
        if(n<0) return 0;
        if(n==0) return arr[0];
        
        if(dp[n] != -1) return dp[n];
        
        int include = solveMem(arr,dp, n-2) + arr[n];
        int exclude = solveMem(arr,dp, n-1) + 0;
        
        dp[n]=max(include,exclude);
        return dp[n];
    }
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // int ans= solve(arr,n-1);
        // return ans;
        
        vector<int> dp(n, -1);
        return solveMem(arr,dp,n-1);
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