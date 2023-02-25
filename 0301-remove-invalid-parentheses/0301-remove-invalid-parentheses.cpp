class Solution {
    public:
    vector<string> ans;
    unordered_map<string,int> mp;
    int getMinInvalid(string s)
    {
        stack<char> st;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(') st.push('(');
            else if(s[i]==')')
            {
                if(!st.empty() && st.top()=='(') st.pop();
                else st.push(')');
            }
        }
        return st.size();
    }
    
    void solve(string s, int invalid)
    {
        //to avoid repeat
        if(mp[s]!=0) return;
        else mp[s]++;
        
        //base case
        if(invalid < 0) return;
        
        if(invalid == 0)
        {
            if(getMinInvalid(s)==0) ans.push_back(s);
            return;
        }
        
        for(int i=0;i<s.length();i++)
        {
            string left=s.substr(0,i);
            string right=s.substr(i+1);
            solve(left+right,invalid-1);
        }
        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        int invalid= getMinInvalid(s);
        solve(s,invalid);
        return ans;
    }
};