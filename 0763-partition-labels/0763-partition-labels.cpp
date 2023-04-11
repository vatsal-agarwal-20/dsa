class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> end_index(26,0);
        for(int i=0;i<s.length();i++)
        {
            end_index[s[i]-'a'] = i;
        }
        
        vector<int> res;
        int start=0,maxIndex=0;
        for(int i=0;i<s.length();i++)
        {
            maxIndex = max(maxIndex, end_index[s[i]-'a']);
            
            if(i==maxIndex)
            {
                res.push_back(i-start+1);
                start=i+1;
            }
        }
        return res;
    }
};