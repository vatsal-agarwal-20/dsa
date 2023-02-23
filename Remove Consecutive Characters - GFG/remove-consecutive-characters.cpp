//{ Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 


// } Driver Code Ends
class Solution{
    
    public:
    string removeConsecutiveCharacter(string S)
    {
        int n= S.length();
        if(n==0 || n==1) return S;
        
        if(S[0]==S[1])
        {
            int index=0;
            while(S[index]==S[0] && index<n)
            {
                index++;
            }
            return S[0]+removeConsecutiveCharacter(S.substr(index));
        }
        return S[0]+removeConsecutiveCharacter(S.substr(1));
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 




// } Driver Code Ends