//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    vector<int> vis(26,0);
		    string ans="";
		    vector<char> v;
		    
		    for(int i=0;i<A.length();i++)
		    {
		        if( ! vis[A[i]-'a'] )
		        {
		            v.push_back(A[i]);
		        }
		        vis[A[i]-'a']++;
		        
		        int flag=0;
		        int m= v.size();
		        for(int i=0;i<m;i++)
		        {
		            if(vis[v[i]-'a']==1)
		            {
		                ans.push_back(v[i]);
		                flag=1;
		                break;
		            }
		        }
		        if(flag==0)
		        {
		            ans.push_back('#');
		        }
		    }
		    return ans;
		}

};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends