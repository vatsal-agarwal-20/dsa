class Solution {
    bool isSafe(int x, int y, int iniColor, vector<vector<int>> &image, int m, int n, vector<vector<int>> &vis)
    {
        if(x>=0 && x<m && y>=0 && y<n && vis[x][y]==0 && image[x][y]==iniColor) return true;
        
        return false;
    }
    
    void dfs(int m, int n, int row, int col,int iniColor, vector<vector<int>> &ans, vector<vector<int>> &image,vector<vector<int>> &vis, int newColor)
    {
        ans[row][col]=newColor;
        vis[row][col]=1;
        
        if(isSafe(row+1,col,iniColor,image,m,n,vis))
        {
            dfs(m,n,row+1,col,iniColor,ans,image,vis,newColor);
        }
        if(isSafe(row-1,col,iniColor,image,m,n,vis))
        {
            dfs(m,n,row-1,col,iniColor,ans,image,vis,newColor);
        }
        if(isSafe(row,col+1,iniColor,image,m,n,vis))
        {
            dfs(m,n,row,col+1,iniColor,ans,image,vis,newColor);
        }
        if(isSafe(row,col-1,iniColor,image,m,n,vis))
        {
            dfs(m,n,row,col-1,iniColor,ans,image,vis,newColor);
        }
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int m= image.size();
        int n= image[0].size();
        vector<vector<int>> vis(m, vector<int>(n,0));
        
        dfs(m,n,sr,sc,iniColor,ans,image,vis,color);
        
        return ans;
    }
};