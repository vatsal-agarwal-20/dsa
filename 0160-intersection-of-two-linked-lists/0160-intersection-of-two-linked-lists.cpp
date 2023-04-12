/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    int length(ListNode *head)
    {
        if(head == NULL) return 0;
        ListNode* curr=head;
        int count=0;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        return count;
    }
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr1=headA;
        ListNode* curr2=headB;
        
        if(headA == NULL || headB == NULL) return NULL;
        
        int n = length(headA);
        int m = length(headB);
        
        int diff = abs(n-m);
        if(n>m)
        {
            while(diff > 0)
            {
                diff--;
                curr1=curr1->next;
            }
        }
        else
        {
            while(diff > 0)
            {
                diff--;
                curr2=curr2->next;
            }
        }
        
        while(curr1 !=NULL && curr2 !=NULL)
        {
            if(curr1 == curr2) return curr1;
            
            curr1=curr1->next;
            curr2=curr2->next;
        }
        return NULL;
    }
};