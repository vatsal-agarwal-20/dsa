class Solution {
    public:
    int lengthOfLongestSubstring(string s) {
        int arr[256]={0};
        int l=0,r=0;
        int maxi=0;
        while(r<s.length())
        {
            arr[s[r]]++;
            
            while(arr[s[r]] > 1)
            {
                arr[s[l]]--;
                l++;
            }
            maxi=max(maxi,r-l+1);
            r++;
        }
        return maxi;
    }
};