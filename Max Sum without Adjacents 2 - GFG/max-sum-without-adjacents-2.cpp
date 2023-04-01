//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
  public:
  int dp[1000000];
  int solve(vector<int> &a, int n)
  {
      // passing n-1 from main function
      if(n == -1) return 0;
      if(n == 0) return a[0];
      if(n == 1) return a[0]+a[1];
      if(dp[n] != -1) return dp[n];
      
      return dp[n] = max(max(solve(a,n-1), a[n]+solve(a,n-2)), a[n]+a[n-1]+solve(a,n-3));
  }
  int findMaxSum(vector<int>& a){
      //Code Here
      memset(dp,-1,sizeof(dp));
      int n=a.size();
      
      return solve(a,n-1);
  }
};

//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> a(n);
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        
        Solution ob;
        int ans = ob.findMaxSum(a);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends