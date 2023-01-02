//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        vector<vector<int>> ans;
        if(arr.size()<4) return ans;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size()-3;i++)
        {
            if((long long)(arr[i]+arr[i+1]+arr[i+2]+arr[i+3])>k) break;
            if((long long)(arr[i]+arr[arr.size()-3]+arr[arr.size()-2]+arr[arr.size()-1])<k) continue;
            if(i>0 && arr[i]==arr[i-1]) continue;
            for(int j=i+1;j<arr.size()-2;j++)
            {
                if(arr[i]+arr[j]+arr[j+1]+arr[j+2]>k) break;
                if(arr[i]+arr[j]+arr[arr.size()-2]+arr[arr.size()-1]<k) continue;
                if(j>i+1 && arr[j]==arr[j-1]) continue;
                int s=j+1;
                int e=arr.size()-1;
                int sum=k-arr[i]-arr[j];
                
                while(s<e)
                {
                    if(arr[s]+arr[e]==sum) 
                    {
                        vector<int> temp;
                        temp.push_back(arr[i]);
                        temp.push_back(arr[j]);
                        temp.push_back(arr[s]);
                        temp.push_back(arr[e]);
                        ans.push_back(temp);
                        
                        while(s<e && arr[s] == temp[2]) s++;
                        while(s<e && arr[e] == temp[3]) e--;
                    }
                    else if(arr[s]+arr[e] > sum)e--;
                    else s++;
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends