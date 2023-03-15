class Solution {
    bool isSafe(int x, int y, int iniColor,int newColor, vector<vector<int>> &image, int m, int n, vector<vector<int>> &ans)
    {
        if(x>=0 && x<m && y>=0 && y<n && ans[x][y]!=newColor && image[x][y]==iniColor) return true;
        
        return false;
    }
    
    void dfs(int m, int n, int row, int col,int iniColor, vector<vector<int>> &ans, vector<vector<int>> &image, int newColor)
    {
        ans[row][col]=newColor;
        
        if(isSafe(row+1,col,iniColor,newColor,image,m,n,ans))
        {
            dfs(m,n,row+1,col,iniColor,ans,image,newColor);
        }
        if(isSafe(row-1,col,iniColor,newColor,image,m,n,ans))
        {
            dfs(m,n,row-1,col,iniColor,ans,image,newColor);
        }
        if(isSafe(row,col+1,iniColor,newColor,image,m,n,ans))
        {
            dfs(m,n,row,col+1,iniColor,ans,image,newColor);
        }
        if(isSafe(row,col-1,iniColor,newColor,image,m,n,ans))
        {
            dfs(m,n,row,col-1,iniColor,ans,image,newColor);
        }
        return;
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> ans = image;
        int m= image.size();
        int n= image[0].size();
        
        dfs(m,n,sr,sc,iniColor,ans,image,color);
        
        return ans;
    }
};