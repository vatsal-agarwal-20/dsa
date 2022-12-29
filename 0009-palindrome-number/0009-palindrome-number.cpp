class Solution {
public:
    bool isPalindrome(int x) {
        int n=x;long r=0;
        if(x<0) return 0;
        while(n!=0)
        {
            int d=n%10;
            r=(r*10)+d;
            n/=10;
        }
        if(r==x) return 1;
        else return 0;
    }
};