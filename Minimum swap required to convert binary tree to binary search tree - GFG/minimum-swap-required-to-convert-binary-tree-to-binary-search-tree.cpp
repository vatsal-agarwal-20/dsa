//{ Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    void inOrder(vector<int>&A, int n, int i, vector<int> & B) {
   if (i >= n) return;
   
    inOrder(A, n, 2*i+1,B); // 2*i+1 gave the left subtree
   B.push_back(A[i]);
    inOrder(A, n, 2*i+2,B); // 2*i+2 gave right subtree
}
    
    int minswap(vector<int>&nums)
    {
    
    vector<pair<int, int> > v; 
    
    for( int i = 0 ; i < nums.size() ;i++){
        v.push_back(make_pair(nums[i], i)); 
    }
    
    sort( v.begin() , v.end() );
    int count = 0 ;
   
    for(int i = 0 ; i < nums.size() ;i++)
    {
       if( nums[i] == v[i].first) continue ;
       else {
           
           count++;
           swap(v[v[i].second] , v[i]);
           i--;
       }
    }
    return count;
}
  public:
    int minSwaps(vector<int>&A, int n){
        //Write your code here
        vector<int> b ;
       inOrder(A , n , 0 , b);
       
       int ans = minswap( b) ;
       
       return ans ;
    }
    
    
};

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin >> n;
	    vector<int>A(n);
	    for(int i = 0 ; i < n; i++){
	        cin >> A[i];
	    }
	    Solution ob;
	    int ans = ob.minSwaps(A, n);
	    cout << ans<<endl;
	}
	return 0;
}

// } Driver Code Ends