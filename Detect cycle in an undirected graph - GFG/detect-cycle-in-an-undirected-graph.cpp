//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
    
    ///////////////////////////
//     bool isCyclicBfs(vector<int> adj[],unordered_map<int,bool> &visited, int node)
//     {
//         unordered_map<int,int> parent;
        
//         parent[node]= -1;
//         queue<int> q;
        
//         q.push(node);
//         visited[node]=1;
        
//         while(!q.empty())
//         {
//             int frontNode= q.front();
//             q.pop();
            
//             for(auto i: adj[frontNode])
//             {
//                 if(visited[i]==1 && i != parent[frontNode])
//                 {
//                     return true;
//                 }
//                 else if(!visited[i])
//                 {
//                     q.push(i);
//                     visited[i]=1;
//                     parent[i]=frontNode;
//                 }
//             }
//         }
//         return false;
//     }
//   public:
//     // Function to detect cycle in an undirected graph.
//     bool isCycle(int V, vector<int> adj[]) {
//         // Code here
//         unordered_map<int,bool> visited;
        
//         for(int i=0;i<V;i++)
//         {
//             if(!visited[i])
//             {
//                 bool ans=isCyclicBfs(adj,visited,i);
//                 if(ans==1) return true;
//             }
//         }
//         return false;
//     }
    ///////////////////////////
    
    
    bool isCyclicDfs(vector<int> adj[],unordered_map<int,bool> &visited, int node, int parent)
    {
        visited[node]=1;
        
        for(auto i: adj[node])
        {
            if(!visited[i])
            {
                bool cycleDetected= isCyclicDfs(adj,visited,i,node);
                if(cycleDetected)
                return true;
            }
            else if(i != parent)
            {
                return true;
            }
        }
        return false;
    }
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        // Code here
        unordered_map<int,bool> visited;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                bool ans=isCyclicDfs(adj,visited,i,-1);
                if(ans==1) return true;
            }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends