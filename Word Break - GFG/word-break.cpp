//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
    unordered_map<string,int> dp;
    int solve(string s,vector<string> &B)
    {
        int l=s.length();
        
        if(l==0) return 1;
        if(dp[s] != 0) return dp[s];
        
        for(int i=1;i<=l;i++)
        {
            int flag=0;
            string ss= s.substr(0,i);
            for(int j=0;j<B.size();j++)
            {
                if(ss.compare(B[j]) == 0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1 && solve(s.substr(i,l-i),B) == 1)
            {
                return dp[s]=1;
            }
        }
        return dp[s]= -1;
    }
public:
    int wordBreak(string A, vector<string> &B) {
        //code here
        int x= solve(A,B);
        if(x==1) return 1;
        else return 0;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends