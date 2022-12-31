class Solution {
public:
    string countAndSay(int n, string s="1") {
        
        if(n==1) return s;
        
        // string s= countAndSay(n-1);
        string res="";
        
        int counter=0;
        for(int i=0;i<s.length();i++)
        {
            counter++;
            if(i== s.length()-1 || s[i] != s[i+1])
            {
                res=res+to_string(counter)+s[i];
                counter=0;
            }
        }
        return countAndSay(n-1,res);
    }
};