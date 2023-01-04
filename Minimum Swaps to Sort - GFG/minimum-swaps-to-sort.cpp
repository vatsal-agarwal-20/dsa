//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    vector<pair<int,int>> temp(nums.size());
	    for(int i=0;i<nums.size();i++)
	    {
	        temp[i]={nums[i],i};
	    }
	    sort(temp.begin(),temp.end());
	    
	    int c=0;
	    for(int i=0;i<nums.size();i++)
	    {
	        if(temp[i].second != i)
	        {
	            c++;
	            swap(temp[i],temp[temp[i].second]);
	            i--;
	        }
	    }
	    return c;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends