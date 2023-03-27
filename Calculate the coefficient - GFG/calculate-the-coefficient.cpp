//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++


class Solution{
    public:
    long long int mod=1e9+7;
    int permutationCoeff(int n, int k){
        //Code here
        long long int p=1;
        
        for(int i=0;i<k;i++)
        {
            p=p*(n-i);
            p=p%mod;
        }
        return p;
    }
};


//{ Driver Code Starts.



int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        Solution ob;
        int ans = ob.permutationCoeff(n,k);
        cout<<ans<<endl;
    }
}
// } Driver Code Ends