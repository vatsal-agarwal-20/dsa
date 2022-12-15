class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        int n1= -2; int n2= -1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>=0)
            {
                ans[n1+2]=nums[i];
                n1+=2;
            }
            else
            {
                ans[n2+2]=nums[i];
                n2+=2;
            }
    }
        return ans;
    }
};