//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
    void solve(vector<vector<int>> &matrix, int xs, int ys, int xd, int yd, int currLen, int &length)
    {
        if(xs==xd && ys==yd)
        {
            if(currLen>length)
            {
                length=currLen;
            }
            return;
        }
        vector<pair<int,int>> directions={{0,1},{0,-1},{1,0},{-1,0}};
        
        matrix[xs][ys]=2;
        
        for(int i=0;i<4;i++)
        {
            int newX= xs + directions[i].first;
            int newY= ys + directions[i].second;
            
            if(newX>=0 && newX<matrix.size() && newY>=0 && newY<matrix[0].size() && matrix[newX][newY]==1)
            {
                solve(matrix,newX,newY,xd,yd,currLen+1,length);
            }
        }
        matrix[xs][ys]=1;
    }
public:
    int longestPath(vector<vector<int>> matrix, int xs, int ys, int xd, int yd)
    {
        // code here
        if(matrix[xs][ys]==0 || matrix[xd][yd]==0) return -1;
        int length= -1;
        solve(matrix,xs,ys,xd,yd,0,length);
        return length;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        int xs, ys, xd, yd;
        cin >> xs >> ys >> xd >> yd;
        vector<vector<int>> mat(n, vector<int>(m));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> mat[i][j];
            }
        }
        Solution ob;
        int ans = ob.longestPath(mat, xs, ys, xd, yd);
        cout << ans;
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends