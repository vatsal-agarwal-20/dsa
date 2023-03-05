//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends


class Solution
{
    void solve(int k,string &str, string &max, int index)
    {
        if(k==0) return;
        
        int l=str.length();
        char maxc=str[index];
        for(int i=index+1;i<l;i++)
        {
            if(maxc < str[i])
            maxc=str[i];
        }
        
        if(maxc != str[index]) k--;
        
        for(int i=index;i<l;i++)
        {
            //max found to swap
            if(str[i]==maxc)
            {
                swap(str[index],str[i]);
                if(str.compare(max) > 0)
                {
                    max=str;
                }
                // k already minus kr chuke h upar condition mein
                solve(k,str,max,index+1);
                
                //backtrack
                swap(str[i],str[index]);
            }
        }
    }
    public:
    //Function to find the largest number after k swaps.
    string findMaximumNum(string str, int k)
    {
       // code here.
       string max=str;
       solve(k,str,max,0);
       return max;
    }
};

//{ Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}

// } Driver Code Ends