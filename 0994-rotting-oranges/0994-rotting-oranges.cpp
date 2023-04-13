class Solution {
    bool isSafe(int a, int b, int m, int n)
    {
        if(a==m || b==n || a<0 || b<0) return false;
        
        return true;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int fresh=0;
        queue<pair<int,int>> q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1) fresh++;
                if(grid[i][j]==2) q.push({i,j});
            }
        }
        
        int count= -1;
        vector<vector<int>> dir = {{0,1}, {0,-1}, {1,0}, {-1,0}};
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                pair<int,int> curr = q.front();
            q.pop();
            
            for(auto& x: dir)
            {
                int a = curr.first + x[0];
                int b = curr.second + x[1];
                
                if(grid[curr.first][curr.second] == 2 && isSafe(a,b,m,n) && grid[a][b] == 1)
                {
                    q.push({a,b});
                    grid[a][b] = 2;
                    fresh--;
                }
            }    
            }
            count++;
        }
        if(fresh > 0) return -1;
        if(count == -1) return 0;
        return count;
    }
};