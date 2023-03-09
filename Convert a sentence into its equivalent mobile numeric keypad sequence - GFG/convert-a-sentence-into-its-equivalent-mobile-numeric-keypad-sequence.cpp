//{ Driver Code Starts
// C++ implementation to convert a
// sentence into its equivalent
// mobile numeric keypad sequence
#include <bits/stdc++.h>
using namespace std;
string printSequence(string input);
// Driver function
int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
    {
        string s;
        getline(cin,s);
        cout<<printSequence(s)<<endl;
    }
	return 0;
}

// } Driver Code Ends

string solve(string str[], string &S)
{
    string output="";
    
    int n=S.length();
    for(int i=0;i<n;i++)
    {
        if(S[i] == ' ')
        {
            output+= '0';
        }
        
        else
        {
            int pos= S[i]-'A';
            output += str[pos];
        }
    }
    return output;
}

string printSequence(string S)
{
    //code here.
    string str[]
        = { "2",   "22",  "222", "3",   "33",   "333", "4",
            "44",  "444", "5",   "55",  "555",  "6",   "66",
            "666", "7",   "77",  "777", "7777", "8",   "88",
            "888", "9",   "99",  "999", "9999" };
    
    cout<<solve(str,S);
}