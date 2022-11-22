//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    bool isSafe(int row,int col,vector<vector<int>> &board,int n)
    {
        int x=row;
        int y=col;
        
        // left to right insertion kr rhe hai toh fir right side check krne ki need hi nhi h
        //row check
        while(y>=0)
        {
            if(board[x][y]==1)
            return false;
            
            y--;
        }
        //column check ki need nhi h kyunki humlog already sirf ek hi element daal rhe column mein
        
        //diagonal check
        x=row;
        y=col;
        
        while(x>=0 && y>=0)
        {
            if(board[x][y]==1)
            return false;
            
            x--;
            y--;
        }
        
        x=row;
        y=col;
        
        while(x<n && y>=0)
        {
            if(board[x][y]==1)
            return false;
            
            x++;
            y--;
        }
        
        return true;
    }
    void addSolution(vector<vector<int>> &board,vector<vector<int>> &ans,int n)
    {
        vector<int> temp;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                //temp.push_back(board[i][j]);
                if(board[i][j]==1)
                temp.push_back(j+1);
            }
        }
        ans.push_back(temp);
    }
    void solve(int col,vector<vector<int>> &board,vector<vector<int>> &ans,int n)
    {
        if(col==n)
        {
            addSolution(board,ans,n);
            return;
        }
        
        // Solve 1 case and recursion will take care
        for(int row=0;row<n;row++)
        {
            if(isSafe(row,col,board,n))
            {
                board[row][col]=1;
                solve(col+1,board,ans,n);
                
                //Backtrack
                board[row][col]=0;
            }
        }
    }
public:
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> board(n, vector<int>(n,0));
        vector<vector<int>> ans;
        
        solve(0,board,ans,n);
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends