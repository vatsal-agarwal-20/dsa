//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to return minimum number of jumps to end of array

class Solution{
  public:
    int minJumps(int arr[], int n){
        // Your code here
        int pos=0;
        int des=0;
        int jumps=0;
        
        if(n==1) return 0;
        if(arr[0]==0) return -1;
        
        for(int i=0;i<n-1;i++)
        {
            des=max(des,arr[i]+i);
            
            if(i==pos)
            {
                pos=des;
                jumps++;
            }
        }
        if(des < n-1) return -1;

        return jumps;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
        Solution obj;
        cout<<obj.minJumps(arr, n)<<endl;
    }
    return 0;
}

// } Driver Code Ends