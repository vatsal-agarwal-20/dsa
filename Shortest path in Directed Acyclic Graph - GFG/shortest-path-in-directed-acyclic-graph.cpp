//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
    void dfs(int node, unordered_map<int, list<pair<int,int>>> &adj, unordered_map<int,bool> &visited, stack<int> &s)
    {
        visited[node]=true;
        for(auto i: adj[node])
        {
            if(!visited[i.first])
            {
                dfs(i.first,adj,visited,s);
            }
        }
        s.push(node);
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        unordered_map<int, list<pair<int,int>>> adj;
        for(int i=0;i<M;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];
            int w=edges[i][2];
            
            pair<int,int> p=make_pair(v,w);
            adj[u].push_back(p);
        }
        unordered_map<int,bool> visited;
        stack<int> s;
        
        for(int i=0;i<N;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,s);
            }
        }
        vector<int> distance(N);
        int src=0;
        
        for(int i=0;i<N;i++)
        {
            distance[i]= INT_MAX;
        }
        distance[src]=0;
        
        
        while(!s.empty())
        {
            int top=s.top();
            s.pop();
            
            if(distance[top]!= INT_MAX)
            {
                for(auto i: adj[top])
                {
                    if(distance[top]+ i.second < distance[i.first])
                    {
                        distance[i.first] = distance[top]+ i.second;
                    }
                }
            }
        }
        for(int i=0;i<N;i++)
        {
            if(distance[i]== INT_MAX) distance[i]= -1;
        }
        return distance;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }
        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends