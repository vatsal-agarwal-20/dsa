#include <bits/stdc++.h> 
#include <iostream>
using namespace std;
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    // Write your code here.
    unordered_map<int,list<pair<int,int>>> adj;
    for(int i=0;i<edges;i++)
    {
        int u= vec[i][0];
        int v= vec[i][1];
        int w= vec[i][2];
        
        adj[u].push_back(make_pair(v,w));
        adj[v].push_back(make_pair(u,w));
    }
    
    vector<int> distance(vertices);
    for(int i=0;i<vertices;i++)
    {
        distance[i]=INT_MAX;
    }
    
    set<pair<int,int>> st;
    
    distance[source]=0;
    st.insert(make_pair(0,source));
    
    while(!st.empty())
    {
        //fetch top record
        auto top = *(st.begin());
        
        int nodeDistance=top.first;
        int topNode=top.second;
        
        //remove top record
        st.erase(st.begin());
        
        //traverse on neighbours
        for(auto neighbour : adj[topNode])
        {
            if(nodeDistance + neighbour.second < distance[neighbour.first])
            {
                auto record = st.find(make_pair(distance[neighbour.first],neighbour.first));
                
                // if record found
                if(record !=st.end())
                {
                    st.erase(record);
                }
                
                //distance update
                distance[neighbour.first]=nodeDistance + neighbour.second;
                // record push in set
                st.insert(make_pair(distance[neighbour.first],neighbour.first));
            }
        }
    }
    return distance;
}

int main()
{

return 0;
}