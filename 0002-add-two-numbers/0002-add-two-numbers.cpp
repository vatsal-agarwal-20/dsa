/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode* ans = new ListNode(NULL);
        ListNode* curr3=ans;
        
        int carry=0;
        while(curr1!=NULL && curr2!=NULL)
        {
            int sum=curr1->val + curr2->val + carry;
            carry = sum/10;
            sum=sum%10;
            ListNode* temp = new ListNode(sum);
            ans->next=temp;
            ans=ans->next;
            
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        while(curr1 != NULL)
        {
            int sum=curr1->val + carry;
            carry = sum/10;
            sum=sum%10;
            ListNode* temp = new ListNode(sum);
            ans->next=temp;
            ans=ans->next;
            
            curr1 = curr1->next;
        }
        while(curr2 != NULL)
        {
            int sum= curr2->val + carry;
            carry = sum/10;
            sum=sum%10;
            ListNode* temp = new ListNode(sum);
            ans->next=temp;
            ans=ans->next;
            
            curr2 = curr2->next;
        }
        if(carry != 0)
        {
            ListNode* temp = new ListNode(carry);
            ans->next=temp;
            ans=ans->next;
        }
        curr3=curr3->next;
        return curr3;
    }
};