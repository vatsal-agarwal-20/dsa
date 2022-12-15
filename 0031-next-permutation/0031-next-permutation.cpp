class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(nums.size()==0) return;
        
        int breakPoint= -1;
        
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]> nums[i-1])
            {
                breakPoint=i-1;
                break;
            }
        }
        if(breakPoint<0)
        {
            reverse(nums.begin(),nums.end());
            return;
        }
        
        for(int i=nums.size()-1;i>breakPoint;i--)
        {
            if(nums[i]>nums[breakPoint])
            {
                swap(nums[i],nums[breakPoint]);
                reverse(nums.begin()+breakPoint+1,nums.end());
                return;
            }
        }
    }
};