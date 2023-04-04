class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int k=0,count=0;
        for(auto i: nums)
        {
            if(i == 0) count++;
            else nums[k++]=i;
        }
        while(count>0)
        {
            nums[k++]=0;
            count--;
        }
    }
};