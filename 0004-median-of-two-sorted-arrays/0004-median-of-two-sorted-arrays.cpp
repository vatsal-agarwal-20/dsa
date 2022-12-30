class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        // When length of the two arrays are different then we do binary search on the
        // shortest array to avoid index out of bounds
        
        if(nums1.size() > nums2.size())
        {
            return findMedianSortedArrays(nums2,nums1);
        }
        
        int n1=nums1.size();
        int n2=nums2.size();
        int s=0,e=n1;
        
        while(s <= e)
        {
            //Initialize cuts or partitions
            int cut1= s+(e-s)/2;
            
            //Total required - already present
            int cut2 = ((n1+n2)/2)-cut1;
            
            //Initialize l1,l2,r1,r2
            int l1= (cut1==0) ? INT_MIN : nums1[cut1-1];
            int l2= (cut2==0) ? INT_MIN : nums2[cut2-1];
            
            int r1= (cut1==n1) ? INT_MAX : nums1[cut1];
            int r2= (cut2==n2) ? INT_MAX : nums2[cut2];
            
            // Check partition validation conditions
            // 1. l1 <= r2   2. l2 <= r1 these two are valid conditions
            // If the above two conditions are not true then we shift 
            // the position of the cut
            if(l1 > r2)
            {
                e= cut1-1;
            }
            else if(l2 > r1)
            {
                s= cut1+1;
            }
            else // Matlab ab upar ki 2 conditions valid hai 
            {
                // Check for even length
                if((n1+n2)%2==0)
                {
                    return (double)((max(l1,l2)+min(r1,r2))/2.0);
                }
                else
                {
                    // Odd length
                    
                    return (double)(min(r1,r2));
                }
            }
        }
        return 0.0; // to avoid error
    }
};