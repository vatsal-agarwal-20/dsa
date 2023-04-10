class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1=num1.length();
        int l2=num2.length();
        
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        
        string ans="";
        
        int i=0,j=0,carry=0;
        while(i<l1 && j<l2)
        {
            int sum= (num1[i]-'0') + (num2[j]-'0') + carry;
            carry=sum/10;
            sum=sum%10;
            ans = ans + to_string(sum); 
            i++;
            j++;
        }
        while(i<l1)
        {
            int sum= (num1[i]-'0') + carry;
            carry=sum/10;
            sum=sum%10;
            ans = ans + to_string(sum);
            i++;
        }
        while(j<l2)
        {
            int sum= (num2[j]-'0') + carry;
            carry=sum/10;
            sum=sum%10;
            ans = ans + to_string(sum);
            j++;
        }
        if(carry != 0 ) ans+= to_string(carry);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};