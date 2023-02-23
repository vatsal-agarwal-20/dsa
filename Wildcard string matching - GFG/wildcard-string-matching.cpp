//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function template for C++
class Solution{
    bool solve(string &pattern, string &wild, int i, int j)
    {
        if(i<0 && j<0) return true;
        if(i>=0 && j<0) return false;
        if(i<0 && j>=0)
        {
            for(int a=0;a<=j;a++)
            {
                if(wild[a] != '*') return false;
            }
            return true;
        }
        
        if(pattern[i] == wild[j] || wild[j]=='?')
        {
            solve(pattern,wild,i-1,j-1);
        }
        else if(wild[j] == '*')
        {
            return (solve(pattern,wild,i-1,j) || solve(pattern,wild,i,j-1));
        }
        else return false;
    }
    public:
    bool match(string wild, string pattern)
    {
        // code here
        return solve(pattern,wild,pattern.length()-1,wild.length()-1);
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}
// } Driver Code Ends