class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int num1=INT_MAX,num2=INT_MAX;
        
        for(auto i: nums)
        {
            if(i<=num1)
                num1=i;
            else if(i<=num2)
                num2=i;
            else 
                return true;
        }
        return false;
    }
};