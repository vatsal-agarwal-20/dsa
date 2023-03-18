//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            // code here   
             vector<int> res(n, 0);
            vector<int> adj[n+1];
            queue<int> q;
            vector<int> indegree(n+1, 0);
            for(int i=0; i<m; i++) {
                // edges[i][0]
                // edges[i][1]
                indegree[edges[i][1]]++;
                adj[edges[i][0]].push_back(edges[i][1]);
            }
            
            for(int i=1; i<n+1; i++) {
                if(indegree[i]==0) {
                    q.push(i);
                    res[i-1]++;
                }
            }
            
            while(q.size()>0) {
                int x = q.front(); q.pop();
                
                for(int frd : adj[x]) {
                    indegree[frd]--;
                    if(indegree[frd]==0) q.push(frd);
                    res[frd-1] = max(res[frd-1], 1 + res[x-1]);
                }
            }
            return res;
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
        cin>>n;
        int m;
        cin>>m;
        vector<vector<int>> edges(m,vector<int>(2));
        for(int i=0;i<m;i++)
            cin>>edges[i][0]>>edges[i][1];
        Solution s;
        vector<int> ans=s.minimumTime(n,edges,m);
        for(auto j:ans)
            cout<<j<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends