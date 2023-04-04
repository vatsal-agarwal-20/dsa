class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1);
        
//         suppose we have nCr and we have to find nC(r+1), like 5C3 and 5C4
// ==> 5C3 = 5*4*3 / 1*2*3

// to get the next term we multiply numerator with its next term and denominator with its next term. As,
// ==> 5C4 = 5*4*3 * 2 / 1*2*3 * 4
        // numerator will be decreaing by 1 and
        // numerator will be increasing by 1
        
        long temp=1;
        ans[0]=ans[rowIndex]=1;
        for(int i=1, up=rowIndex, down=1;i<rowIndex;up--, down++, i++)
        {
            temp = temp * up/down;
            ans[i]=temp;
        }
        return ans;
    }
};