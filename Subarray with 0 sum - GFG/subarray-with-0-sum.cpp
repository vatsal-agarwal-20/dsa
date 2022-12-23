//{ Driver Code Starts
// A C++ program to find if there is a zero sum
// subarray
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
    public:
    //Complete this function
    //Function to check whether there is a subarray present with 0-sum or not.
    bool subArrayExists(int arr[], int n)
    {
        //Your code here
        
        // 3 conditions need to be checked
        
        /* i. Prefix sum is repeated i.e. for {4,2,-3,1,9}
              we have prefix sum as {4,6,3,4,13}
              we can see 4 is repeating which means between it we got a sum
              equal to zero 
              
          ii. We getting a subarray from starting index i.e for {3,-1,-2,9}
              prefix sum is {3,2,0,9}
              we get 0 in prefix sum
              
         iii. An element in array is 0 itself*/
         unordered_map<int,int> m;
         int prefix_sum=0;
         for(int i=0;i<n;i++)
         {
             if(arr[i]==0) return true;
             prefix_sum+=arr[i];
             m[prefix_sum]++;
         }
         for(auto i:m)
         {
             if(i.first == 0) return true;
             if(i.second >1) return true;
         }
         return false;
    }
};

//{ Driver Code Starts.
// Driver code
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i=0;i<n;i++)
	    cin>>arr[i];
	    Solution obj;
	    	if (obj.subArrayExists(arr, n))
		cout << "Yes\n";
	else
		cout << "No\n";
	}
	return 0;
}
// } Driver Code Ends