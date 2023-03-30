//{ Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        int mod = 1e9+7;
        if(n==0) return 0;
        if(n==1) return k;
        long long same =k%mod;
        long long diff=(k*(k-1))%mod;
        
        for(long long i=3;i<=n;i++)
        {
            long long prev =diff%mod;
            diff = ((same+diff)*(k-1))%mod;
            same=prev%mod;
        }
        return (same+diff)%mod;
    }
};

//{ Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}
// } Driver Code Ends